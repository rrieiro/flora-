//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __LORA_OMNET_SIMPLELORAAPP_H_
#define __LORA_OMNET_SIMPLELORAAPP_H_

#include <omnetpp.h>
#include "inet/common/lifecycle/ILifecycle.h"
#include "inet/common/lifecycle/NodeStatus.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/lifecycle/LifecycleOperation.h"

#include "LoRaAppPacket_m.h"
#include "LoRa/LoRaMacControlInfo_m.h"

#include "inet/physicallayer/energyconsumer/StateBasedEpEnergyConsumer.h"

using namespace omnetpp;

namespace inet {

/**
 * TODO - Generated class
 */
class INET_API SimpleLoRaApp : public ILifecycle, public inet::physicallayer::StateBasedEpEnergyConsumer {
    protected:
        virtual void initialize(int stage) override;
        void finish() override;
        virtual int numInitStages() const override { return NUM_INIT_STAGES; }
        virtual void handleMessage(cMessage *msg) override;
        virtual bool handleOperationStage(LifecycleOperation *operation, int stage, IDoneCallback *doneCallback) override;

        void handleMessageFromLowerLayer(cMessage *msg);
        std::pair<double,double> generateUniformCircleCoordinates(double radius, double gatewayX, double gatewayY);
        void sendJoinRequest();
        void sendDownMgmtPacket();

        int numberOfPacketsToSend;
        int sentPackets;
        int receivedADRCommands;
        int lastSentMeasurement;
        simtime_t timeToFirstPacket;
        simtime_t timeToNextPacket;

        cMessage *configureLoRaParameters;
        cMessage *sendMeasurements;

        //history of sent packets;
        cOutVector sfVector;
        cOutVector tpVector;


        //variables to control ADR
        bool evaluateADRinNode;
        int ADR_ACK_CNT = 0;
        int ADR_ACK_LIMIT = 64; //64;
        int ADR_ACK_DELAY = 32; //32;
        bool sendNextPacketWithADRACKReq = false;
        void increaseSFIfPossible();

        /* Not related to Lora */
        simtime_t lastTime;


        const simtime_t DataAquisitionInterval = 10*60; // typical 10 min. loop interval

        //microcontroller parameters
        const double MCSleepCurrent = (double)6.15/1000; // 6.15mA
        const double MCWakeCurrent = (double)12.4/1000; // 12.4mA,
        const double MCVoltage = 3.3; // 3,3V typical

        //sensor parameters
        const double SensorVoltage = 5.0; // 3,3 - 6V
        const simtime_t SensorAquisitionTime = 35/1000; // measurement
        const simtime_t SensorMeasuringTime = 2; // data is sensed in background  1,7 - 2s of measuring

        const double SensorSleepCurrent = (double)50/1000000; // 50uA
        const double SensorMeasurementCurrent = (double)1.5/1000 ; // 1,5mA (measuring) for 5V
        const double SensorAquisitionCurrent = (double)0.8/1000 ; // 0,8mA for 5V


        double totalMCEnergyConsumed = 0;
        double totalSensorEnergyConsumed = 0;


        cOutVector messageDelayVector;
        cOutVector elapsedTimeVector;
        cOutVector MCEnergyVector;
        cOutVector sensorEnergyVector;

        simtime_t LoraNicStartTime;
        simtime_t LoraNicEndTime;
        bool NictimeConsumed = false;

        void receiveSignal(cComponent *source, simsignal_t signalID, long value, cObject *details) override;

    public:
        SimpleLoRaApp() {}
        simsignal_t LoRa_AppPacketSent;
        //LoRa physical layer parameters
        double loRaTP;
        units::values::Hz loRaCF;
        int loRaSF;
        units::values::Hz loRaBW;
        int loRaCR;
        bool loRaUseHeader;
};

}

#endif
