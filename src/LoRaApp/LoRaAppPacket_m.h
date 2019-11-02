//
// Generated file, do not edit! Created by nedtool 5.5 from LoRaApp/LoRaAppPacket.msg.
//

#ifndef __LORAAPPPACKET_M_H
#define __LORAAPPPACKET_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0505
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Enum generated from <tt>LoRaApp/LoRaAppPacket.msg:21</tt> by nedtool.
 * <pre>
 * enum AppPacketType
 * {
 *     JOIN_REQUEST = 1;
 *     JOIN_REPLY = 2;
 *     DATA = 3;
 *     TXCONFIG = 4;
 * }
 * </pre>
 */
enum AppPacketType {
    JOIN_REQUEST = 1,
    JOIN_REPLY = 2,
    DATA = 3,
    TXCONFIG = 4
};

/**
 * Class generated from <tt>LoRaApp/LoRaAppPacket.msg:28</tt> by nedtool.
 * <pre>
 * class LoRaOptions
 * {
 *     double LoRaTP = -1;
 *     double LoRaCF = -1;
 *     int LoRaSF = -1;
 *     double LoRaBW = -1;
 *     int LoRaCR = -1;
 *     bool UseHeader = true;
 *     bool ADRACKReq = false;
 * }
 * </pre>
 */
class LoRaOptions : public ::omnetpp::cObject
{
  protected:
    double LoRaTP;
    double LoRaCF;
    int LoRaSF;
    double LoRaBW;
    int LoRaCR;
    bool UseHeader;
    bool ADRACKReq;

  private:
    void copy(const LoRaOptions& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LoRaOptions&);

  public:
    LoRaOptions();
    LoRaOptions(const LoRaOptions& other);
    virtual ~LoRaOptions();
    LoRaOptions& operator=(const LoRaOptions& other);
    virtual LoRaOptions *dup() const override {return new LoRaOptions(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getLoRaTP() const;
    virtual void setLoRaTP(double LoRaTP);
    virtual double getLoRaCF() const;
    virtual void setLoRaCF(double LoRaCF);
    virtual int getLoRaSF() const;
    virtual void setLoRaSF(int LoRaSF);
    virtual double getLoRaBW() const;
    virtual void setLoRaBW(double LoRaBW);
    virtual int getLoRaCR() const;
    virtual void setLoRaCR(int LoRaCR);
    virtual bool getUseHeader() const;
    virtual void setUseHeader(bool UseHeader);
    virtual bool getADRACKReq() const;
    virtual void setADRACKReq(bool ADRACKReq);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LoRaOptions& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LoRaOptions& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>LoRaApp/LoRaAppPacket.msg:38</tt> by nedtool.
 * <pre>
 * packet LoRaAppPacket
 * {
 *     int msgType \@enum(AppPacketType);
 *     int sampleMeasurement;
 *     LoRaOptions options;
 * }
 * </pre>
 */
class LoRaAppPacket : public ::omnetpp::cPacket
{
  protected:
    int msgType;
    int sampleMeasurement;
    LoRaOptions options;

  private:
    void copy(const LoRaAppPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LoRaAppPacket&);

  public:
    LoRaAppPacket(const char *name=nullptr, short kind=0);
    LoRaAppPacket(const LoRaAppPacket& other);
    virtual ~LoRaAppPacket();
    LoRaAppPacket& operator=(const LoRaAppPacket& other);
    virtual LoRaAppPacket *dup() const override {return new LoRaAppPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getMsgType() const;
    virtual void setMsgType(int msgType);
    virtual int getSampleMeasurement() const;
    virtual void setSampleMeasurement(int sampleMeasurement);
    virtual LoRaOptions& getOptions();
    virtual const LoRaOptions& getOptions() const {return const_cast<LoRaAppPacket*>(this)->getOptions();}
    virtual void setOptions(const LoRaOptions& options);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LoRaAppPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LoRaAppPacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef __LORAAPPPACKET_M_H

