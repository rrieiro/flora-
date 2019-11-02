//
// Generated file, do not edit! Created by nedtool 5.5 from LoRa/LoRaMacFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "LoRaMacFrame_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(LoRaMacFrame)

LoRaMacFrame::LoRaMacFrame(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->sequenceNumber = 0;
    this->LoRaTP = 0;
    this->LoRaSF = 0;
    this->LoRaCR = 0;
    this->LoRaUseHeader = false;
    this->RSSI = 0;
    this->SNIR = 0;
}

LoRaMacFrame::LoRaMacFrame(const LoRaMacFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

LoRaMacFrame::~LoRaMacFrame()
{
}

LoRaMacFrame& LoRaMacFrame::operator=(const LoRaMacFrame& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void LoRaMacFrame::copy(const LoRaMacFrame& other)
{
    this->transmitterAddress = other.transmitterAddress;
    this->receiverAddress = other.receiverAddress;
    this->sequenceNumber = other.sequenceNumber;
    this->LoRaTP = other.LoRaTP;
    this->LoRaCF = other.LoRaCF;
    this->LoRaSF = other.LoRaSF;
    this->LoRaBW = other.LoRaBW;
    this->LoRaCR = other.LoRaCR;
    this->LoRaUseHeader = other.LoRaUseHeader;
    this->RSSI = other.RSSI;
    this->SNIR = other.SNIR;
}

void LoRaMacFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->transmitterAddress);
    doParsimPacking(b,this->receiverAddress);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->LoRaTP);
    doParsimPacking(b,this->LoRaCF);
    doParsimPacking(b,this->LoRaSF);
    doParsimPacking(b,this->LoRaBW);
    doParsimPacking(b,this->LoRaCR);
    doParsimPacking(b,this->LoRaUseHeader);
    doParsimPacking(b,this->RSSI);
    doParsimPacking(b,this->SNIR);
}

void LoRaMacFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->transmitterAddress);
    doParsimUnpacking(b,this->receiverAddress);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->LoRaTP);
    doParsimUnpacking(b,this->LoRaCF);
    doParsimUnpacking(b,this->LoRaSF);
    doParsimUnpacking(b,this->LoRaBW);
    doParsimUnpacking(b,this->LoRaCR);
    doParsimUnpacking(b,this->LoRaUseHeader);
    doParsimUnpacking(b,this->RSSI);
    doParsimUnpacking(b,this->SNIR);
}

DevAddr& LoRaMacFrame::getTransmitterAddress()
{
    return this->transmitterAddress;
}

void LoRaMacFrame::setTransmitterAddress(const DevAddr& transmitterAddress)
{
    this->transmitterAddress = transmitterAddress;
}

DevAddr& LoRaMacFrame::getReceiverAddress()
{
    return this->receiverAddress;
}

void LoRaMacFrame::setReceiverAddress(const DevAddr& receiverAddress)
{
    this->receiverAddress = receiverAddress;
}

int LoRaMacFrame::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void LoRaMacFrame::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

double LoRaMacFrame::getLoRaTP() const
{
    return this->LoRaTP;
}

void LoRaMacFrame::setLoRaTP(double LoRaTP)
{
    this->LoRaTP = LoRaTP;
}

inet::units::values::Hz& LoRaMacFrame::getLoRaCF()
{
    return this->LoRaCF;
}

void LoRaMacFrame::setLoRaCF(const inet::units::values::Hz& LoRaCF)
{
    this->LoRaCF = LoRaCF;
}

int LoRaMacFrame::getLoRaSF() const
{
    return this->LoRaSF;
}

void LoRaMacFrame::setLoRaSF(int LoRaSF)
{
    this->LoRaSF = LoRaSF;
}

inet::units::values::Hz& LoRaMacFrame::getLoRaBW()
{
    return this->LoRaBW;
}

void LoRaMacFrame::setLoRaBW(const inet::units::values::Hz& LoRaBW)
{
    this->LoRaBW = LoRaBW;
}

int LoRaMacFrame::getLoRaCR() const
{
    return this->LoRaCR;
}

void LoRaMacFrame::setLoRaCR(int LoRaCR)
{
    this->LoRaCR = LoRaCR;
}

bool LoRaMacFrame::getLoRaUseHeader() const
{
    return this->LoRaUseHeader;
}

void LoRaMacFrame::setLoRaUseHeader(bool LoRaUseHeader)
{
    this->LoRaUseHeader = LoRaUseHeader;
}

double LoRaMacFrame::getRSSI() const
{
    return this->RSSI;
}

void LoRaMacFrame::setRSSI(double RSSI)
{
    this->RSSI = RSSI;
}

double LoRaMacFrame::getSNIR() const
{
    return this->SNIR;
}

void LoRaMacFrame::setSNIR(double SNIR)
{
    this->SNIR = SNIR;
}

class LoRaMacFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LoRaMacFrameDescriptor();
    virtual ~LoRaMacFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(LoRaMacFrameDescriptor)

LoRaMacFrameDescriptor::LoRaMacFrameDescriptor() : omnetpp::cClassDescriptor("inet::LoRaMacFrame", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

LoRaMacFrameDescriptor::~LoRaMacFrameDescriptor()
{
    delete[] propertynames;
}

bool LoRaMacFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoRaMacFrame *>(obj)!=nullptr;
}

const char **LoRaMacFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LoRaMacFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LoRaMacFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int LoRaMacFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *LoRaMacFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "transmitterAddress",
        "receiverAddress",
        "sequenceNumber",
        "LoRaTP",
        "LoRaCF",
        "LoRaSF",
        "LoRaBW",
        "LoRaCR",
        "LoRaUseHeader",
        "RSSI",
        "SNIR",
    };
    return (field>=0 && field<11) ? fieldNames[field] : nullptr;
}

int LoRaMacFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transmitterAddress")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiverAddress")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+2;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaTP")==0) return base+3;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaCF")==0) return base+4;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaSF")==0) return base+5;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaBW")==0) return base+6;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaCR")==0) return base+7;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaUseHeader")==0) return base+8;
    if (fieldName[0]=='R' && strcmp(fieldName, "RSSI")==0) return base+9;
    if (fieldName[0]=='S' && strcmp(fieldName, "SNIR")==0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LoRaMacFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "DevAddr",
        "DevAddr",
        "int",
        "double",
        "inet::units::values::Hz",
        "int",
        "inet::units::values::Hz",
        "int",
        "bool",
        "double",
        "double",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : nullptr;
}

const char **LoRaMacFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LoRaMacFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LoRaMacFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LoRaMacFrame *pp = (LoRaMacFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LoRaMacFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LoRaMacFrame *pp = (LoRaMacFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoRaMacFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LoRaMacFrame *pp = (LoRaMacFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getTransmitterAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getReceiverAddress(); return out.str();}
        case 2: return long2string(pp->getSequenceNumber());
        case 3: return double2string(pp->getLoRaTP());
        case 4: {std::stringstream out; out << pp->getLoRaCF(); return out.str();}
        case 5: return long2string(pp->getLoRaSF());
        case 6: {std::stringstream out; out << pp->getLoRaBW(); return out.str();}
        case 7: return long2string(pp->getLoRaCR());
        case 8: return bool2string(pp->getLoRaUseHeader());
        case 9: return double2string(pp->getRSSI());
        case 10: return double2string(pp->getSNIR());
        default: return "";
    }
}

bool LoRaMacFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LoRaMacFrame *pp = (LoRaMacFrame *)object; (void)pp;
    switch (field) {
        case 2: pp->setSequenceNumber(string2long(value)); return true;
        case 3: pp->setLoRaTP(string2double(value)); return true;
        case 5: pp->setLoRaSF(string2long(value)); return true;
        case 7: pp->setLoRaCR(string2long(value)); return true;
        case 8: pp->setLoRaUseHeader(string2bool(value)); return true;
        case 9: pp->setRSSI(string2double(value)); return true;
        case 10: pp->setSNIR(string2double(value)); return true;
        default: return false;
    }
}

const char *LoRaMacFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(DevAddr));
        case 1: return omnetpp::opp_typename(typeid(DevAddr));
        case 4: return omnetpp::opp_typename(typeid(inet::units::values::Hz));
        case 6: return omnetpp::opp_typename(typeid(inet::units::values::Hz));
        default: return nullptr;
    };
}

void *LoRaMacFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LoRaMacFrame *pp = (LoRaMacFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getTransmitterAddress()); break;
        case 1: return (void *)(&pp->getReceiverAddress()); break;
        case 4: return (void *)(&pp->getLoRaCF()); break;
        case 6: return (void *)(&pp->getLoRaBW()); break;
        default: return nullptr;
    }
}

} // namespace inet

