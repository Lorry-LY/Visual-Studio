#ifndef SIGNATURES_H
#define SIGNATURES_H

#include <string>
#include <vector>
#include "number.h"

using namespace std;

enum SigType
{
    DSA,
    Schnorr
};

class Signature
{
public:
    // Todo
    Signature() {};
    ~Signature() {};

    virtual void Print()const;
    virtual vector<Number> getNumbers()const;
    SigType GetType() const;
    
};

class SchnorrSignature : public Signature
{
public:
    //Todo
    SchnorrSignature(const Number* s, const Number* e) :s(s), e(e) {};
    ~SchnorrSignature() { delete s;delete e; };

    void Print() const
    {
        cout << "s=";
        s->Print();
        cout << ", e=";
        e->Print();
        cout << endl;
    }

    vector<Number> getNumbers()const
    {
        vector<Number>numbers = { *s,*e };
        return numbers;
    }

    const Number *s;
    const Number *e;
};

class DSASignature : public Signature
{
public:
    //Todo
    DSASignature(const Number* r, const Number* s) :r(r), s(s) {};
    ~DSASignature() { delete r; delete s; };

    void Print() const
    {
        cout << "r=";
        r->Print();
        cout << ", s=";
        s->Print();
        cout << endl;
    }

    vector<Number> getNumbers()const
    {
        vector<Number>numbers = { *r,*s };
        return numbers;
    }

    const Number *r;
    const Number *s;
};

class PublicKey
{
public:
    //Todo
    PublicKey() {};
    ~PublicKey() {};

    virtual void Print()const;
    virtual bool Verify(const string& message,const Signature& sig)const;
};

class SchnorrPublicKey : public PublicKey
{
public:
    const Number *y;
    SchnorrPublicKey(const Number *y) : y(y) {}
    ~SchnorrPublicKey() { delete y; };

    bool Verify(const string &message, const Signature &signature) const;
    void Print() const
    {
        cout << "Schnorr Public Key is: ";
        y->Print();
        cout << endl;
    };
};
class DSAPublicKey : public PublicKey
{
public:
    const Number *y;
    //Todo
    DSAPublicKey(const Number* y) : y(y) {}
    ~DSAPublicKey() { delete y; };

    
    void Print() const
    {
        cout << "DSA Public Key is: ";
        y->Print();
        cout << endl;
    }
    bool Verify(const string& message, const Signature& signature) const;
};

class SecretKey
{
public:
    //Todo
    SecretKey() {};
    ~SecretKey() {};

    virtual const Signature* Sign(const string& message) const;

};

class SchnorrSecretKey : public SecretKey
{
public:
    const Number *x;
    //Todo 
    SchnorrSecretKey(const Number* x) :x(x) {};
    ~SchnorrSecretKey() { delete x; };
    
    void Print() const
    {
        cout << "Schnorr Secret Key is: ";
        x->Print();
        cout << endl;
    };
    const Signature* Sign(const string& message) const;
};
class DSASecretKey : public SecretKey
{
public:
    const Number *x;

    DSASecretKey(const Number* x) : x(x) {};
    ~DSASecretKey() { delete x; };

    const Signature *Sign(const string &message) const;

    void Print() const
    {
        cout << "DSA Secret Key is: ";
        x->Print();
        cout << endl;
    }
};

class SigPair
{
public:
    const PublicKey *publicKey; 
    const SecretKey *secretKey; 
    SigPair(const PublicKey *publicKey, const SecretKey *secretKey);
    ~SigPair();
};

const SigPair *GenerateKey(SigType sigType, const string &info);        //Éú³ÉKey

vector<SigType> SigTypes();

#endif