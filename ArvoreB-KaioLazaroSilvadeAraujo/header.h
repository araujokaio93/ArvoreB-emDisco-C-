/********************************************************
 *      Árvore B em disco                               *
 *                                                      *
 * Autores:   Kaio Lázaro Silva de Araújo               *
 *                                                      *
 *                                                      *
 ********************************************************/
#ifndef HEADER_H
#define HEADER_H

#include "serializable.h"

class header : public serializable {
public:
    header();
    header(const string type, unsigned int version);
    header(const header &h);
    virtual ~header();
    header operator=(const header &h);
    bool operator==(const header &h);
    unsigned long long int getFirstDeleted() const;
    void setFirstDeleted(unsigned long long int firstDeleted);
    unsigned long long int getRoot() const;
    void setRoot(unsigned long long int root);
    string getType() const;
    void setType(string type);
    unsigned int getVersion() const;
    void setVersion(unsigned int version);
    virtual string toString();
    virtual void fromString(string repr);
    virtual string toXML() { return ""; };
    virtual void fromXML(string repr) {};
    virtual string toCSV() { return ""; };
    virtual void fromCSV(string repr){};
    virtual string toJSON() { return ""; };
    virtual void fromJSON(string repr) {};
    virtual unsigned long long int size() const;

protected:
    string type;
    unsigned int version;
    unsigned long long int root;
    unsigned long long int firstDeleted;
};

#endif // HEADER_H
