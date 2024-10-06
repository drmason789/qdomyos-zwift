#include <QRegularExpression>
#include "productindex.h"

std::vector<QString> ProductIndex::allProducts;
QMap<QString, QString> ProductIndex::allIdentifiers;

static const QRegularExpression validIdentifierRegex("^\\w+$");

const QString ProductIndex::AddProduct(const QString &name, const QString& identifier)
{
    if(name==nullptr)
        throw std::invalid_argument("Name must not be null.");

    if(identifier==nullptr || identifier=="")
        throw std::invalid_argument("Identifier must be provided.");

    if(!validIdentifierRegex.match(identifier).hasMatch())
        throw std::invalid_argument("Identifier must be alphanumeric");

    if(allIdentifiers.contains(name)) {
        throw std::invalid_argument("Product name already defined: " + name.toStdString());
    }

    allProducts.push_back(name);
    allIdentifiers[name] = identifier;

    return name;
}

ProductIndex::ProductIndex() {}

const QString ProductIndex::Identifier(const QString &productName) { return allIdentifiers[productName]; }

#define DEFINE_PRODUCT(ProductKey, ProductName) \
        const QString ProductIndex::ProductKey = AddProduct(QStringLiteral(ProductName), QStringLiteral(#ProductKey));

DEFINE_PRODUCT(ActivioTreadmill, "Activio Treadmill");
DEFINE_PRODUCT(ApexBike, "Apex Bike");
DEFINE_PRODUCT(BHFitnessElliptical, "BH Fitness Elliptical");
DEFINE_PRODUCT(BKoolBike, "BKool Bike");
DEFINE_PRODUCT(BowflexT216Treadmill, "Bowflex T216 Treadmill");
DEFINE_PRODUCT(CSCBike_Named, "CSC Bike (Named)");
DEFINE_PRODUCT(CSCBike, "CSC Bike");
DEFINE_PRODUCT(Chronobike, "Chronobike");
DEFINE_PRODUCT(ComputrainerBike, "Computrainer Bike");
DEFINE_PRODUCT(Concept2SkiErg, "Concept2 Ski Erg");
DEFINE_PRODUCT(DomyosBike, "Domyos Bike");
DEFINE_PRODUCT(DomyosElliptical, "Domyos Elliptical");
DEFINE_PRODUCT(DomyosRower, "Domyos Rower");
DEFINE_PRODUCT(DomyosTreadmill, "Domyos Treadmill");
DEFINE_PRODUCT(ESLinkerTreadmill, "ES Linker Treadmill");
DEFINE_PRODUCT(EchelonConnectSportBike, "Echelon Connect Sport Bike");
DEFINE_PRODUCT(EchelonRower, "Echelon Rower");
DEFINE_PRODUCT(EchelonStrideTreadmill, "Echelon Stride Treadmill");
DEFINE_PRODUCT(EliteSterzoSmart, "Elite Sterzo Smart");
DEFINE_PRODUCT(FTMSAccessory, "FTMS Accessory");
DEFINE_PRODUCT(FTMSBikeHammer, "FTMS Bike Hammer 64123");
DEFINE_PRODUCT(FTMSBikeIConsole, "FTMS Bike IConsole");
DEFINE_PRODUCT(FTMSBikeHammerRacerS, "FTMS Bike Hammer Racer S");
DEFINE_PRODUCT(FTMSBike, "FTMS Bike");
DEFINE_PRODUCT(FTMSBike2, "FTMS Bike 2");
DEFINE_PRODUCT(FTMSKICKRCORE, "FTMS KICKR CORE");
DEFINE_PRODUCT(FTMSRower, "FTMS Rower");
DEFINE_PRODUCT(FakeBike, "Fake Bike");
DEFINE_PRODUCT(FakeElliptical, "Fake Elliptical");
DEFINE_PRODUCT(FakeTreadmill, "Fake Treadmill");
DEFINE_PRODUCT(FitPlusBike_MRK_NoSettings, "FitPlus Bike (MRK, no settings)");
DEFINE_PRODUCT(FitPlusF5, "FitPlus F5");
DEFINE_PRODUCT(FitShowBF, "FitShow BF");
DEFINE_PRODUCT(FitShowFS, "FitShow FS");
DEFINE_PRODUCT(FitShowSW, "FitShow SW");
DEFINE_PRODUCT(FlywheelBike, "Flywheel Bike");
DEFINE_PRODUCT(FlywheelLifeFitnessIC8, "Flywheel Life Fitness IC8");
DEFINE_PRODUCT(FocusTreadmill, "Focus Treadmill");
DEFINE_PRODUCT(HorizonGR7Bike, "Horizon GR7 Bike");
DEFINE_PRODUCT(HorizonTreadmill_Bodytone, "Horizon Treadmill (Bodytone)");
DEFINE_PRODUCT(HorizonTreadmill_DomyosTC, "Horizon Treadmill (Domyos TC)");
DEFINE_PRODUCT(HorizonTreadmill_Toorx, "Horizon Treadmill (Toorx)");
DEFINE_PRODUCT(HorizonTreadmill, "Horizon Treadmill");
DEFINE_PRODUCT(InspireBike, "Inspire Bike");
DEFINE_PRODUCT(KeepBike, "Keep Bike");
DEFINE_PRODUCT(KingsmithR1ProTreadmill, "Kingsmith R1 Pro Treadmill");
DEFINE_PRODUCT(KingsmithR2Treadmill, "Kingsmith R2 Treadmill");
DEFINE_PRODUCT(LifeFitnessTreadmill, "Life Fitness Treadmill");
DEFINE_PRODUCT(M3IBike, "M3I Bike");
DEFINE_PRODUCT(MCFBike, "MCF Bike");
DEFINE_PRODUCT(MepanelBike, "Mepanel Bike");
DEFINE_PRODUCT(NPECableBike, "NPE Cable Bike");
DEFINE_PRODUCT(NPECableBike_Excluding_FlywheelLifeFitnessIC8, "NPECable Bike (excluding Flywheel Life Fitness IC8)");
DEFINE_PRODUCT(NautilusBike, "Nautilus Bike");
DEFINE_PRODUCT(NautilusElliptical, "Nautilus Elliptical");
DEFINE_PRODUCT(NautilusTreadmill, "Nautilus Treadmill");
DEFINE_PRODUCT(NordictrackIFitADBTreadmill, "Nordictrack IFit ADB Treadmill");
DEFINE_PRODUCT(NorditrackElliptical, "Norditrack Elliptical");
DEFINE_PRODUCT(OctaneElliptical, "Octane Elliptical");
DEFINE_PRODUCT(OctaneTreadmill, "Octane Treadmill");
DEFINE_PRODUCT(PafersBike, "Pafers Bike");
DEFINE_PRODUCT(PafersTreadmill, "Pafers Treadmill");
DEFINE_PRODUCT(ProFormRower, "ProForm Rower");
DEFINE_PRODUCT(ProFormTreadmill, "ProForm Treadmill");
DEFINE_PRODUCT(ProFormWifiBike, "ProForm Wifi Bike");
DEFINE_PRODUCT(ProFormWifiTreadmill, "ProForm Wifi Treadmill");
DEFINE_PRODUCT(ProformBike, "Proform Bike");
DEFINE_PRODUCT(ProformEllipticalTrainer, "Proform Elliptical Trainer");
DEFINE_PRODUCT(ProformElliptical, "Proform Elliptical");
DEFINE_PRODUCT(RenphoBike_ToorxFTMS, "Renpho Bike (Toorx FTMS)");
DEFINE_PRODUCT(RenphoBike, "Renpho Bike");
DEFINE_PRODUCT(RenphoBike2, "Renpho Bike 2");
DEFINE_PRODUCT(Schwinn170Bike, "Schwinn 170 Bike");
DEFINE_PRODUCT(SchwinnIC4Bike, "Schwinn IC4 Bike");
DEFINE_PRODUCT(Shuaa5Treadmill, "Shuaa5 Treadmill");
DEFINE_PRODUCT(SkandikaWiryBike, "Skandika Wiry Bike");
DEFINE_PRODUCT(SmartRowRower, "Smart Row Rower");
DEFINE_PRODUCT(SnodeBikeFS, "Snode Bike FS");
DEFINE_PRODUCT(SoleBike, "Sole Bike");
DEFINE_PRODUCT(SoleElliptical, "Sole Elliptical");
DEFINE_PRODUCT(SoleF80Treadmill, "Sole F80 Treadmill");
DEFINE_PRODUCT(SoleF85Treadmill, "Sole F85 Treadmill");
DEFINE_PRODUCT(SpiritTreadmill, "Spirit Treadmill");
DEFINE_PRODUCT(SportsPlusBike, "Sports Plus Bike");
DEFINE_PRODUCT(SportsTechBike, "Sports Tech Bike");
DEFINE_PRODUCT(StagesBike_Assioma_PowerSensorDisabled, "Stages Bike (Assioma / Power Sensor disabled)");
DEFINE_PRODUCT(StagesBike_KICKRCORE, "Stages Bike (KICKR CORE)");
DEFINE_PRODUCT(StagesBike, "Stages Bike");
DEFINE_PRODUCT(StrydeRunTreadmill_PowerSensor, "StrydeRun Treadmill / Power Sensor");
DEFINE_PRODUCT(TacxNeo2Bike, "Tacx Neo 2 Bike");
DEFINE_PRODUCT(TechnoGymMyRunTreadmillRFComm, "TechnoGym MyRun Treadmill RF Comm");
DEFINE_PRODUCT(TechnoGymMyRunTreadmill, "TechnoGym MyRun Treadmill");
DEFINE_PRODUCT(ToorxAppGateUSBBike_EnabledInSettings, "Toorx AppGate USB Bike (Enabled in settings)");
DEFINE_PRODUCT(ToorxAppGateUSBBike, "Toorx AppGate USB Bike");
DEFINE_PRODUCT(ToorxAppGateUSBTreadmill, "Toorx AppGate USB Treadmill");
DEFINE_PRODUCT(ToorxTreadmill, "Toorx Treadmill");
DEFINE_PRODUCT(TrueTreadmill, "True Treadmill");
DEFINE_PRODUCT(TrxAppGateUSBElliptical, "TrxAppGateUSB Elliptical");
DEFINE_PRODUCT(UltrasportBike, "Ultrasport Bike");
DEFINE_PRODUCT(WahooKickrSnapBike, "Wahoo Kickr Snap Bike");
DEFINE_PRODUCT(YesoulBike, "Yesoul Bike");
DEFINE_PRODUCT(YpooElliptical, "Ypoo Elliptical");
DEFINE_PRODUCT(ZwiftRunpod, "Zwift Runpod");
DEFINE_PRODUCT(iConceptBike, "iConcept Bike");
DEFINE_PRODUCT(iConceptElliptical, "iConcept Elliptical");
DEFINE_PRODUCT(SnodeBikeTF, "Snode Bike TF");
DEFINE_PRODUCT(ZiproTreadmill, "Zipro Treadmill");

