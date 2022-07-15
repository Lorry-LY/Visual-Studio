#include "../include/signatures.h"
#include "../include/number.h"

void Signature::Print() const
{
}

vector<Number> Signature::getNumbers() const
{
	return vector<Number>();
}


SigType Signature::GetType() const
{
	string name = typeid(*this).name();

	if (name == "class DSASignature")
		return DSA;
	else if (name == "class SchnorrSignature")
		return Schnorr;
	else
		throw invalid_argument("Signature Type does not exist!");
}

//Todo: Constructors/Destructors

bool SchnorrPublicKey::Verify(const string& message, const Signature& signature) const
{
	//Todo
	vector<Number>numbers = signature.getNumbers();
	Number s = numbers[0];
	Number e = numbers[1];
	if (Number::NSign(s) <= 0 || Number::NSign(e) <= 0)return false;
	Number rv = Number::Mul_Mod(Number::Pow(*Number::G, s, *Number::P), Number::Pow((*this->y), e, *Number::P), *Number::P);
	Number ev = Number::Mod(Number::Hash(rv, message), *Number::Q);
	if (ev.ToString() == e.ToString())return true;
	return false;
}


bool DSAPublicKey::Verify(const string& message, const Signature& signature) const
{
	//Todo
	vector<Number>numbers = signature.getNumbers();
	Number r = numbers[0];
	Number s = numbers[1];
	if (Number::NSign(r) <= 0 || Number::NSign(s) <= 0)return false;
	Number w = Number::Inv(s, *Number::Q);
	Number z = Number::Hash(message);
	Number u1 = Number::Mul_Mod(z, w, *Number::Q);
	Number u2 = Number::Mul_Mod(r, w, *Number::Q);
	Number res = Number::Mul_Mod(Number::Pow(*Number::G, u1, *Number::P), Number::Pow((*this->y), u2, *Number::P), *Number::P);
	if (Number::Mod(res, *Number::Q).ToString() == r.ToString())return true;
	else return false;

}



const Signature* SchnorrSecretKey::Sign(const string& message) const
{
	//Todo
	while (true)
	{
		Number k = Number::Rand(1, *Number::Q);
		Number r = Number::Pow(*Number::G, k, *Number::P);
		Number e = Number::Mod(Number::Hash(r, message), *Number::Q);
		Number s = Number::Mod(Number::Sub(k, Number::Mul_Mod((*this->x), e, *Number::Q)), *Number::Q);
		if(Number::NSign(s) > 0 && Number::NSign(e) > 0)
			return new SchnorrSignature(new Number(s), new Number(e));
	}
}



const Signature* DSASecretKey::Sign(const string& message) const
{
	while (true)
	{
		Number k = Number::Rand(1, *Number::Q);
		Number r = Number::Mod(Number::Pow(*Number::G, k, *Number::P), *Number::Q);
		Number z = Number::Hash(message);
		Number zxr = Number::Mod(Number::Add(z, Number::Mul_Mod(*(this->x), r, *Number::Q)), *Number::Q);
		Number ki = Number::Inv(k, *Number::Q);
		Number s = Number::Mul_Mod(ki, zxr, *Number::Q);

		if (Number::NSign(r) > 0 && Number::NSign(s) > 0)
			return new DSASignature(new Number(r), new Number(s));
	}
}

SigPair::SigPair
(const PublicKey* publicKey, const SecretKey* secretKey)
	: publicKey(publicKey), secretKey(secretKey)
{
}

SigPair::~SigPair()
{
	cout << "Destruct SigPair..." << endl;
	delete publicKey;
	delete secretKey;
}

const SigPair* GenerateKey(SigType sigType, const string& info)
{
	if (sigType == DSA)
	{
		Number x = Number::Rand(Number(1), *Number::Q);
		Number y = Number::Pow(*Number::G, x, *Number::P);
		const Number* newX = new Number(x);
		const Number* newY = new Number(y);

		DSASecretKey* sk = new DSASecretKey(newX);
		DSAPublicKey* pk = new DSAPublicKey(newY);

		SigPair* sigPair = new SigPair(pk, sk);

		return sigPair;
	}
	else if (sigType == Schnorr)
	{
		//Todo
		Number x = Number::Rand(Number(1), *Number::Q);
		Number y = Number::Pow(*Number::G, x, *Number::P);
		const Number* newX = new Number(x);
		const Number* newY = new Number(y);

		SchnorrSecretKey* sk = new SchnorrSecretKey(newX);
		SchnorrPublicKey* pk = new SchnorrPublicKey(newY);

		SigPair* sigPair = new SigPair(pk, sk);

		return sigPair;
	}
	return nullptr;
}

vector<SigType> SigTypes()
{
	vector<SigType> s;
	s.push_back(DSA);
	s.push_back(Schnorr);
	return s;
}

void PublicKey::Print() const
{
}

bool PublicKey::Verify(const string& message, const Signature& sig) const
{
	return false;
}

const Signature* SecretKey::Sign(const string& message) const
{
	return nullptr;
}
