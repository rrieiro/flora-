//
// Generated file, do not edit! Created by nedtool 5.5 from LoRaPhy/LoRaRadioControlInfo.msg.
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
#include "LoRaRadioControlInfo_m.h"

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
namespace physicallayer {

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::physicallayer::LoRaRadioCommandCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::physicallayer::LoRaRadioCommandCode"));
    e->insert(LORA_RADIO_C_CONFIGURE, "LORA_RADIO_C_CONFIGURE");
)

Register_Class(LoRaConfigureRadioCommand)

LoRaConfigureRadioCommand::LoRaConfigureRadioCommand() : ::omnetpp::cObject()
{
    this->radioMode = -1;
}

LoRaConfigureRadioCommand::LoRaConfigureRadioCommand(const LoRaConfigureRadioCommand& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

LoRaConfigureRadioCommand::~LoRaConfigureRadioCommand()
{
}

LoRaConfigureRadioCommand& LoRaConfigureRadioCommand::operator=(const LoRaConfigureRadioCommand& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void LoRaConfigureRadioCommand::copy(const LoRaConfigureRadioCommand& other)
{
    this->radioMode = other.radioMode;
    this->power = other.power;
    this->bitrate = other.bitrate;
    this->carrierFrequency = other.carrierFrequency;
    this->bandwidth = other.bandwidth;
}

void LoRaConfigureRadioCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->radioMode);
    doParsimPacking(b,this->power);
    doParsimPacking(b,this->bitrate);
    doParsimPacking(b,this->carrierFrequency);
    doParsimPacking(b,this->bandwidth);
}

void LoRaConfigureRadioCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->radioMode);
    doParsimUnpacking(b,this->power);
    doParsimUnpacking(b,this->bitrate);
    doParsimUnpacking(b,this->carrierFrequency);
    doParsimUnpacking(b,this->bandwidth);
}

int LoRaConfigureRadioCommand::getRadioMode() const
{
    return this->radioMode;
}

void LoRaConfigureRadioCommand::setRadioMode(int radioMode)
{
    this->radioMode = radioMode;
}

inet::units::values::W& LoRaConfigureRadioCommand::getPower()
{
    return this->power;
}

void LoRaConfigureRadioCommand::setPower(const inet::units::values::W& power)
{
    this->power = power;
}

inet::units::values::bps& LoRaConfigureRadioCommand::getBitrate()
{
    return this->bitrate;
}

void LoRaConfigureRadioCommand::setBitrate(const inet::units::values::bps& bitrate)
{
    this->bitrate = bitrate;
}

inet::units::values::Hz& LoRaConfigureRadioCommand::getCarrierFrequency()
{
    return this->carrierFrequency;
}

void LoRaConfigureRadioCommand::setCarrierFrequency(const inet::units::values::Hz& carrierFrequency)
{
    this->carrierFrequency = carrierFrequency;
}

inet::units::values::Hz& LoRaConfigureRadioCommand::getBandwidth()
{
    return this->bandwidth;
}

void LoRaConfigureRadioCommand::setBandwidth(const inet::units::values::Hz& bandwidth)
{
    this->bandwidth = bandwidth;
}

class LoRaConfigureRadioCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LoRaConfigureRadioCommandDescriptor();
    virtual ~LoRaConfigureRadioCommandDescriptor();

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

Register_ClassDescriptor(LoRaConfigureRadioCommandDescriptor)

LoRaConfigureRadioCommandDescriptor::LoRaConfigureRadioCommandDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::LoRaConfigureRadioCommand", "omnetpp::cObject")
{
    propertynames = nullptr;
}

LoRaConfigureRadioCommandDescriptor::~LoRaConfigureRadioCommandDescriptor()
{
    delete[] propertynames;
}

bool LoRaConfigureRadioCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoRaConfigureRadioCommand *>(obj)!=nullptr;
}

const char **LoRaConfigureRadioCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LoRaConfigureRadioCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LoRaConfigureRadioCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int LoRaConfigureRadioCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *LoRaConfigureRadioCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "radioMode",
        "power",
        "bitrate",
        "carrierFrequency",
        "bandwidth",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int LoRaConfigureRadioCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "radioMode")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "power")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitrate")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "carrierFrequency")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "bandwidth")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LoRaConfigureRadioCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "inet::units::values::W",
        "inet::units::values::bps",
        "inet::units::values::Hz",
        "inet::units::values::Hz",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **LoRaConfigureRadioCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *LoRaConfigureRadioCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LoRaConfigureRadioCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LoRaConfigureRadioCommand *pp = (LoRaConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LoRaConfigureRadioCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LoRaConfigureRadioCommand *pp = (LoRaConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoRaConfigureRadioCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LoRaConfigureRadioCommand *pp = (LoRaConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getRadioMode());
        case 1: {std::stringstream out; out << pp->getPower(); return out.str();}
        case 2: {std::stringstream out; out << pp->getBitrate(); return out.str();}
        case 3: {std::stringstream out; out << pp->getCarrierFrequency(); return out.str();}
        case 4: {std::stringstream out; out << pp->getBandwidth(); return out.str();}
        default: return "";
    }
}

bool LoRaConfigureRadioCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LoRaConfigureRadioCommand *pp = (LoRaConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setRadioMode(string2long(value)); return true;
        default: return false;
    }
}

const char *LoRaConfigureRadioCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(inet::units::values::W));
        case 2: return omnetpp::opp_typename(typeid(inet::units::values::bps));
        case 3: return omnetpp::opp_typename(typeid(inet::units::values::Hz));
        case 4: return omnetpp::opp_typename(typeid(inet::units::values::Hz));
        default: return nullptr;
    };
}

void *LoRaConfigureRadioCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LoRaConfigureRadioCommand *pp = (LoRaConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getPower()); break;
        case 2: return (void *)(&pp->getBitrate()); break;
        case 3: return (void *)(&pp->getCarrierFrequency()); break;
        case 4: return (void *)(&pp->getBandwidth()); break;
        default: return nullptr;
    }
}

Register_Class(LoRaTransmissionRequest)

LoRaTransmissionRequest::LoRaTransmissionRequest() : ::omnetpp::cObject()
{
}

LoRaTransmissionRequest::LoRaTransmissionRequest(const LoRaTransmissionRequest& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

LoRaTransmissionRequest::~LoRaTransmissionRequest()
{
}

LoRaTransmissionRequest& LoRaTransmissionRequest::operator=(const LoRaTransmissionRequest& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void LoRaTransmissionRequest::copy(const LoRaTransmissionRequest& other)
{
    this->power = other.power;
    this->bitrate = other.bitrate;
    this->carrierFrequency = other.carrierFrequency;
    this->bandwidth = other.bandwidth;
}

void LoRaTransmissionRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->power);
    doParsimPacking(b,this->bitrate);
    doParsimPacking(b,this->carrierFrequency);
    doParsimPacking(b,this->bandwidth);
}

void LoRaTransmissionRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->power);
    doParsimUnpacking(b,this->bitrate);
    doParsimUnpacking(b,this->carrierFrequency);
    doParsimUnpacking(b,this->bandwidth);
}

inet::units::values::W& LoRaTransmissionRequest::getPower()
{
    return this->power;
}

void LoRaTransmissionRequest::setPower(const inet::units::values::W& power)
{
    this->power = power;
}

inet::units::values::bps& LoRaTransmissionRequest::getBitrate()
{
    return this->bitrate;
}

void LoRaTransmissionRequest::setBitrate(const inet::units::values::bps& bitrate)
{
    this->bitrate = bitrate;
}

inet::units::values::Hz& LoRaTransmissionRequest::getCarrierFrequency()
{
    return this->carrierFrequency;
}

void LoRaTransmissionRequest::setCarrierFrequency(const inet::units::values::Hz& carrierFrequency)
{
    this->carrierFrequency = carrierFrequency;
}

inet::units::values::Hz& LoRaTransmissionRequest::getBandwidth()
{
    return this->bandwidth;
}

void LoRaTransmissionRequest::setBandwidth(const inet::units::values::Hz& bandwidth)
{
    this->bandwidth = bandwidth;
}

class LoRaTransmissionRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LoRaTransmissionRequestDescriptor();
    virtual ~LoRaTransmissionRequestDescriptor();

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

Register_ClassDescriptor(LoRaTransmissionRequestDescriptor)

LoRaTransmissionRequestDescriptor::LoRaTransmissionRequestDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::LoRaTransmissionRequest", "omnetpp::cObject")
{
    propertynames = nullptr;
}

LoRaTransmissionRequestDescriptor::~LoRaTransmissionRequestDescriptor()
{
    delete[] propertynames;
}

bool LoRaTransmissionRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoRaTransmissionRequest *>(obj)!=nullptr;
}

const char **LoRaTransmissionRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LoRaTransmissionRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LoRaTransmissionRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int LoRaTransmissionRequestDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *LoRaTransmissionRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "power",
        "bitrate",
        "carrierFrequency",
        "bandwidth",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int LoRaTransmissionRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "power")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitrate")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "carrierFrequency")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "bandwidth")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LoRaTransmissionRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::units::values::W",
        "inet::units::values::bps",
        "inet::units::values::Hz",
        "inet::units::values::Hz",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **LoRaTransmissionRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *LoRaTransmissionRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LoRaTransmissionRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LoRaTransmissionRequest *pp = (LoRaTransmissionRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LoRaTransmissionRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LoRaTransmissionRequest *pp = (LoRaTransmissionRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoRaTransmissionRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LoRaTransmissionRequest *pp = (LoRaTransmissionRequest *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getPower(); return out.str();}
        case 1: {std::stringstream out; out << pp->getBitrate(); return out.str();}
        case 2: {std::stringstream out; out << pp->getCarrierFrequency(); return out.str();}
        case 3: {std::stringstream out; out << pp->getBandwidth(); return out.str();}
        default: return "";
    }
}

bool LoRaTransmissionRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LoRaTransmissionRequest *pp = (LoRaTransmissionRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *LoRaTransmissionRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(inet::units::values::W));
        case 1: return omnetpp::opp_typename(typeid(inet::units::values::bps));
        case 2: return omnetpp::opp_typename(typeid(inet::units::values::Hz));
        case 3: return omnetpp::opp_typename(typeid(inet::units::values::Hz));
        default: return nullptr;
    };
}

void *LoRaTransmissionRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LoRaTransmissionRequest *pp = (LoRaTransmissionRequest *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getPower()); break;
        case 1: return (void *)(&pp->getBitrate()); break;
        case 2: return (void *)(&pp->getCarrierFrequency()); break;
        case 3: return (void *)(&pp->getBandwidth()); break;
        default: return nullptr;
    }
}

Register_Class(LoRaReceptionIndication)

LoRaReceptionIndication::LoRaReceptionIndication() : ::omnetpp::cObject()
{
    this->minSNIR = 0;
    this->LoRaSF = 0;
    this->LoRaCR = 0;
}

LoRaReceptionIndication::LoRaReceptionIndication(const LoRaReceptionIndication& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

LoRaReceptionIndication::~LoRaReceptionIndication()
{
}

LoRaReceptionIndication& LoRaReceptionIndication::operator=(const LoRaReceptionIndication& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void LoRaReceptionIndication::copy(const LoRaReceptionIndication& other)
{
    this->minRSSI = other.minRSSI;
    this->minSNIR = other.minSNIR;
    this->LoRaTP = other.LoRaTP;
    this->LoRaCF = other.LoRaCF;
    this->LoRaSF = other.LoRaSF;
    this->LoRaBW = other.LoRaBW;
    this->LoRaCR = other.LoRaCR;
}

void LoRaReceptionIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->minRSSI);
    doParsimPacking(b,this->minSNIR);
    doParsimPacking(b,this->LoRaTP);
    doParsimPacking(b,this->LoRaCF);
    doParsimPacking(b,this->LoRaSF);
    doParsimPacking(b,this->LoRaBW);
    doParsimPacking(b,this->LoRaCR);
}

void LoRaReceptionIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->minRSSI);
    doParsimUnpacking(b,this->minSNIR);
    doParsimUnpacking(b,this->LoRaTP);
    doParsimUnpacking(b,this->LoRaCF);
    doParsimUnpacking(b,this->LoRaSF);
    doParsimUnpacking(b,this->LoRaBW);
    doParsimUnpacking(b,this->LoRaCR);
}

inet::units::values::W& LoRaReceptionIndication::getMinRSSI()
{
    return this->minRSSI;
}

void LoRaReceptionIndication::setMinRSSI(const inet::units::values::W& minRSSI)
{
    this->minRSSI = minRSSI;
}

double LoRaReceptionIndication::getMinSNIR() const
{
    return this->minSNIR;
}

void LoRaReceptionIndication::setMinSNIR(double minSNIR)
{
    this->minSNIR = minSNIR;
}

inet::units::values::W& LoRaReceptionIndication::getLoRaTP()
{
    return this->LoRaTP;
}

void LoRaReceptionIndication::setLoRaTP(const inet::units::values::W& LoRaTP)
{
    this->LoRaTP = LoRaTP;
}

inet::units::values::Hz& LoRaReceptionIndication::getLoRaCF()
{
    return this->LoRaCF;
}

void LoRaReceptionIndication::setLoRaCF(const inet::units::values::Hz& LoRaCF)
{
    this->LoRaCF = LoRaCF;
}

int LoRaReceptionIndication::getLoRaSF() const
{
    return this->LoRaSF;
}

void LoRaReceptionIndication::setLoRaSF(int LoRaSF)
{
    this->LoRaSF = LoRaSF;
}

inet::units::values::Hz& LoRaReceptionIndication::getLoRaBW()
{
    return this->LoRaBW;
}

void LoRaReceptionIndication::setLoRaBW(const inet::units::values::Hz& LoRaBW)
{
    this->LoRaBW = LoRaBW;
}

int LoRaReceptionIndication::getLoRaCR() const
{
    return this->LoRaCR;
}

void LoRaReceptionIndication::setLoRaCR(int LoRaCR)
{
    this->LoRaCR = LoRaCR;
}

class LoRaReceptionIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LoRaReceptionIndicationDescriptor();
    virtual ~LoRaReceptionIndicationDescriptor();

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

Register_ClassDescriptor(LoRaReceptionIndicationDescriptor)

LoRaReceptionIndicationDescriptor::LoRaReceptionIndicationDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::LoRaReceptionIndication", "omnetpp::cObject")
{
    propertynames = nullptr;
}

LoRaReceptionIndicationDescriptor::~LoRaReceptionIndicationDescriptor()
{
    delete[] propertynames;
}

bool LoRaReceptionIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoRaReceptionIndication *>(obj)!=nullptr;
}

const char **LoRaReceptionIndicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LoRaReceptionIndicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LoRaReceptionIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int LoRaReceptionIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *LoRaReceptionIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "minRSSI",
        "minSNIR",
        "LoRaTP",
        "LoRaCF",
        "LoRaSF",
        "LoRaBW",
        "LoRaCR",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int LoRaReceptionIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "minRSSI")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "minSNIR")==0) return base+1;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaTP")==0) return base+2;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaCF")==0) return base+3;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaSF")==0) return base+4;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaBW")==0) return base+5;
    if (fieldName[0]=='L' && strcmp(fieldName, "LoRaCR")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LoRaReceptionIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::units::values::W",
        "double",
        "inet::units::values::W",
        "inet::units::values::Hz",
        "int",
        "inet::units::values::Hz",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **LoRaReceptionIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *LoRaReceptionIndicationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LoRaReceptionIndicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LoRaReceptionIndication *pp = (LoRaReceptionIndication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LoRaReceptionIndicationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LoRaReceptionIndication *pp = (LoRaReceptionIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoRaReceptionIndicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LoRaReceptionIndication *pp = (LoRaReceptionIndication *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getMinRSSI(); return out.str();}
        case 1: return double2string(pp->getMinSNIR());
        case 2: {std::stringstream out; out << pp->getLoRaTP(); return out.str();}
        case 3: {std::stringstream out; out << pp->getLoRaCF(); return out.str();}
        case 4: return long2string(pp->getLoRaSF());
        case 5: {std::stringstream out; out << pp->getLoRaBW(); return out.str();}
        case 6: return long2string(pp->getLoRaCR());
        default: return "";
    }
}

bool LoRaReceptionIndicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LoRaReceptionIndication *pp = (LoRaReceptionIndication *)object; (void)pp;
    switch (field) {
        case 1: pp->setMinSNIR(string2double(value)); return true;
        case 4: pp->setLoRaSF(string2long(value)); return true;
        case 6: pp->setLoRaCR(string2long(value)); return true;
        default: return false;
    }
}

const char *LoRaReceptionIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(inet::units::values::W));
        case 2: return omnetpp::opp_typename(typeid(inet::units::values::W));
        case 3: return omnetpp::opp_typename(typeid(inet::units::values::Hz));
        case 5: return omnetpp::opp_typename(typeid(inet::units::values::Hz));
        default: return nullptr;
    };
}

void *LoRaReceptionIndicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LoRaReceptionIndication *pp = (LoRaReceptionIndication *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getMinRSSI()); break;
        case 2: return (void *)(&pp->getLoRaTP()); break;
        case 3: return (void *)(&pp->getLoRaCF()); break;
        case 5: return (void *)(&pp->getLoRaBW()); break;
        default: return nullptr;
    }
}

} // namespace physicallayer
} // namespace inet

