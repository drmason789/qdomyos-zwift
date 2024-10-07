#pragma once

#include <vector>
#include <QMap>
#include <QString>

class ProductIndex
{
    static std::vector<QString> allProducts;
    static QMap<QString, QString> allIdentifiers;

    static const QString AddProduct(const QString& name, const QString& identifier);

    ProductIndex();
public:

    static const std::vector<QString> Products() {
        return allProducts;
    }

    static const QString Identifier(const QString& productName);

    static const QString ActivioTreadmill;
    static const QString AntBike;
    static const QString ApexBike;
    static const QString BHFitnessElliptical;
    static const QString BKoolBike;
    static const QString BowflexT216Treadmill;
    static const QString Chronobike;
    static const QString ComputrainerBike;
    static const QString Concept2SkiErg;
    static const QString Crossrope;
    static const QString CSCBike;
    static const QString CSCBike_Named;
    static const QString DomyosBike;
    static const QString DomyosElliptical;
    static const QString DomyosRower;
    static const QString DomyosTreadmill;
    static const QString EchelonConnectSportBike;
    static const QString EchelonRower;
    static const QString EchelonStrideTreadmill;
    static const QString EliteSterzoSmart;
    static const QString ESLinkerTreadmill;
    static const QString FakeBike;
    static const QString FakeElliptical;
    static const QString FakeTreadmill;
    static const QString FitPlusBike_MRK_NoSettings;
    static const QString FitPlusF5;
    static const QString FitShowBF;
    static const QString FitShowFS;
    static const QString FitShowSW;
    static const QString FlywheelBike;
    static const QString FlywheelLifeFitnessIC8;
    static const QString FocusTreadmill;
    static const QString FTMSAccessory;
    static const QString FTMSBike;
    static const QString FTMSBike2;
    static const QString FTMSBike3;
    static const QString FTMSBikeHammer;
    static const QString FTMSBikeHammerRacerS;
    static const QString FTMSBikeIConsole;
    static const QString FTMSKICKRCORE;
    static const QString FTMSRower;
    static const QString HorizonGR7Bike;
    static const QString HorizonTreadmill;
    static const QString HorizonTreadmill_Bodytone;
    static const QString HorizonTreadmill_DomyosTC;
    static const QString HorizonTreadmill_Toorx;
    static const QString iConceptBike;
    static const QString iConceptElliptical;
    static const QString InspireBike;
    static const QString KeepBike;
    static const QString KingsmithR1ProTreadmill;
    static const QString KingsmithR2Treadmill;
    static const QString LifeFitnessTreadmill;
    static const QString M3IBike;
    static const QString MCFBike;
    static const QString MepanelBike;
    static const QString NautilusBike;
    static const QString NautilusElliptical;
    static const QString NautilusTreadmill;
    static const QString NordictrackIFitADBTreadmill;
    static const QString NorditrackElliptical;
    static const QString NPECableBike;
    static const QString NPECableBike_Excluding_FlywheelLifeFitnessIC8;
    static const QString OctaneElliptical;
    static const QString OctaneTreadmill;
    static const QString PafersBike;
    static const QString PafersTreadmill;
    static const QString ProformBike;
    static const QString ProformElliptical;
    static const QString ProformEllipticalTrainer;
    static const QString ProFormRower;
    static const QString ProFormTreadmill;
    static const QString ProFormWifiBike;
    static const QString ProFormWifiTreadmill;
    static const QString RenphoBike;
    static const QString RenphoBike2;
    static const QString RenphoBike_ToorxFTMS;
    static const QString Schwinn170Bike;
    static const QString SchwinnIC4Bike;
    static const QString Shuaa5Treadmill;
    static const QString SkandikaWiryBike;
    static const QString SmartRowRower;
    static const QString SnodeBikeFS;
    static const QString SnodeBikeTF;
    static const QString SoleBike;
    static const QString SoleElliptical;
    static const QString SoleF80Treadmill;
    static const QString SoleF85Treadmill;
    static const QString SpiritTreadmill;
    static const QString SportsPlusBike;
    static const QString SportsTechBike;
    static const QString StagesBike;
    static const QString StagesBike_Assioma_PowerSensorDisabled;
    static const QString StagesBike_KICKRCORE;
    static const QString StrydeRunTreadmill_PowerSensor;
    static const QString TacxNeo2Bike;
    static const QString TechnoGymMyRunTreadmill;
    static const QString TechnoGymMyRunTreadmillRFComm;
    static const QString ToorxAppGateUSBBike;
    static const QString ToorxAppGateUSBBike_EnabledInSettings;
    static const QString ToorxAppGateUSBTreadmill;
    static const QString ToorxTreadmill;
    static const QString TrueTreadmill;
    static const QString TrxAppGateUSBElliptical;
    static const QString UltrasportBike;
    static const QString WahooKickrSnapBike;
    static const QString YesoulBike;
    static const QString YpooElliptical;
    static const QString ZiproTreadmill;
    static const QString ZwiftRunpod;

};


