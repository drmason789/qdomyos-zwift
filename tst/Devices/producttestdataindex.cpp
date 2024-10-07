#include "producttestdataindex.h"
#include "productindex.h"

#include "bluetooth.h"
#include "devicenamepatterngroup.h"
#include "producttestdata.h"
#include "producttestdatabuilder.h"
#include "devicediscoveryinfo.h"
#include "qzsettings.h"




bool ProductTestDataIndex::isInitialized = false;

/**
 * @brief hex2bytes Converts a hexadecimal string to bytes, 2 characters at a time.
 * @param s An hexadecimal string e.g. "023F4A" to  { 0x02, 0x3F, 0x4A }
 */
static QByteArray hex2bytes(const std::string& s)
{
    QByteArray v;

    for (size_t i = 0; i < s.length(); i +=2)
    {
        std::string slice(s, i, 2);
        uint8_t value = std::stoul(slice, 0, 16);
        v.append(value);
    }
    return v;
}

QMap<QString,const ProductTestData*> ProductTestDataIndex::testData;


const std::vector<QString> ProductTestDataIndex::Names() {
    std::vector<QString> result;

    for(auto key : testData.keys())
        result.push_back(key);

    return result;
}

const std::vector<const ProductTestData *> ProductTestDataIndex::TestData() {
    std::vector<const ProductTestData*> result;

    for(auto item : testData)
        result.push_back(item);

    return result;
}

ProductTestDataBuilder *  ProductTestDataIndex::RegisterNewProductTestData(const QString& name)
{
    auto existing = testData.value(name, nullptr);
    if(existing)
        delete existing;
    ProductTestDataBuilder * result = new ProductTestDataBuilder(name);
    testData.insert(name, result);
    return result;
}

const ProductTestData *ProductTestDataIndex::GetProductTestData(const QString &name) {
    if(!isInitialized)
        throw std::invalid_argument("Product test data is not initialized.");

    return testData.value(name, nullptr);
}


QMultiMap<DeviceTypeId, const ProductTestData*> ProductTestDataIndex::WhereExpects(const std::unordered_set<DeviceTypeId> &typeIds) {
    QMultiMap<DeviceTypeId, const ProductTestData*> result;

    if(typeIds.empty())
        return result;

    for(auto item : qAsConst(testData)) {
        if(typeIds.count(item->ExpectedDeviceType()))
            result.insert(item->ExpectedDeviceType(), item);
    }

    return result;
}

void ProductTestDataIndex::Initialize() {

    if(isInitialized)
        return;

    const QString testIP = "1.2.3.4";    

    // Activio Treadmill
    RegisterNewProductTestData(ProductIndex::ActivioTreadmill)
        ->expectDevice<activiotreadmill>()
        ->acceptDeviceName("RUNNERT", DeviceNameComparison::StartsWithIgnoreCase);

    // Apex Bike
    RegisterNewProductTestData(ProductIndex::ApexBike)
        ->expectDevice<apexbike>()
        ->acceptDeviceName("WLT8266BM", DeviceNameComparison::StartsWithIgnoreCase);

    // Ant Bike
    RegisterNewProductTestData(ProductIndex::AntBike)
        ->expectDevice<antbike>()
        ->acceptDeviceName("", DeviceNameComparison::Exact)
        ->configureSettingsWith(QZSettings::antbike);

    // BH Fitness Elliptical
    RegisterNewProductTestData(ProductIndex::BHFitnessElliptical)
        ->expectDevice<bhfitnesselliptical>()
        ->acceptDeviceName("B01_", DeviceNameComparison::StartsWithIgnoreCase);


    // BKool Bike
    RegisterNewProductTestData(ProductIndex::BKoolBike)
        ->expectDevice<bkoolbike>()
        ->acceptDeviceName("BKOOLSMARTPRO", DeviceNameComparison::StartsWithIgnoreCase);

    // Bowflex T216 Treadmill
    RegisterNewProductTestData(ProductIndex::BowflexT216Treadmill)
        ->expectDevice<bowflext216treadmill>()
        ->acceptDeviceName("BOWFLEX T", DeviceNameComparison::StartsWithIgnoreCase);


    //// Bowflex Treadmill
    //RegisterNewProductTestData(ProductIndex::BowflexTreadmill)
    //->expectDevice<bowflexttreadmill>();



    // ChronoBike
    RegisterNewProductTestData(ProductIndex::Chronobike)
        ->expectDevice<chronobike>()
        ->acceptDeviceName("CHRONO ", DeviceNameComparison::StartsWithIgnoreCase);


    // Computrainer Bike
    RegisterNewProductTestData(ProductIndex::ComputrainerBike)
        ->expectDevice<computrainerbike>()
        ->acceptDeviceName("", DeviceNameComparison::StartsWithIgnoreCase)
        ->disable("Unable to emulate serial port for testing");

    // Concept2 Ski Erg
    RegisterNewProductTestData(ProductIndex::Concept2SkiErg)
        ->expectDevice<concept2skierg>()
        ->acceptDeviceName("PM5", "SKI", DeviceNameComparison::IgnoreCase)
        ->acceptDeviceName("PM5", DeviceNameComparison::IgnoreCase);

    // Crossrope
    RegisterNewProductTestData(ProductIndex::Crossrope)
        ->expectDevice<crossrope>()
        ->acceptDeviceName("CROSSROPE", DeviceNameComparison::StartsWithIgnoreCase);

    // CSC Bike (Named)
    QString cscBikeName = "CyclingSpeedCadenceBike-";
    RegisterNewProductTestData(ProductIndex::CSCBike_Named)
        ->expectDevice<cscbike>()        
        ->acceptDeviceName(cscBikeName, DeviceNameComparison::StartsWith)
        ->rejectDeviceName("X" + cscBikeName, DeviceNameComparison::Exact)
        ->configureSettingsWith([cscBikeName](DeviceDiscoveryInfo &info, bool enable) -> void {
            info.setValue(QZSettings::cadence_sensor_name, enable ? cscBikeName : "Disabled");
            info.setValue(QZSettings::cadence_sensor_as_bike, enable);
        });


    cscBikeName = "CyclingSpeedCadenceBike-";
    RegisterNewProductTestData(ProductIndex::CSCBike)
        ->expectDevice<cscbike>()
        ->acceptDeviceName(QStringLiteral("JOROTO-BK-"), DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(
            [cscBikeName](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations)->void
            {
                DeviceDiscoveryInfo config(info);

                if(enable) {
                    // If the Bluetooth name doesn't match the one being tested, but if csc_as_bike is enabled in the settings,
                    // and the bluetooth name does match the cscName in the settings, the device will be detected anyway,
                    // so prevent this by not including that specific configuration
                    //
                    // In order for the search to actually happen, the cscName has to be "Disabled" or csc_as_bike must be true.
                    /*
                                                    config.setValue(QZSettings::csc_as_bike, true);
                                                    config.setValue(QZSettings::cscName, cscBikeName);
                                                    configurations.push_back(config);
                                                    */

                    config.setValue(QZSettings::cadence_sensor_name, "Disabled");
                    config.setValue(QZSettings::cadence_sensor_as_bike, true);
                    configurations.push_back(config);

                    config.setValue(QZSettings::cadence_sensor_name, "Disabled");
                    config.setValue(QZSettings::cadence_sensor_as_bike, false);
                    configurations.push_back(config);

                    config.setValue(QZSettings::cadence_sensor_as_bike, true);
                    config.setValue(QZSettings::cadence_sensor_name,"NOT "+cscBikeName);
                    configurations.push_back(config);
                }
                else  {
                    // prevent the search
                    config.setValue(QZSettings::cadence_sensor_as_bike, false);
                    config.setValue(QZSettings::cadence_sensor_name, "NOT "+cscBikeName);
                    configurations.push_back(config);
                }
            });


    // Domyos bike
    RegisterNewProductTestData(ProductIndex::DomyosBike)
        ->expectDevice<domyosbike>()        
        ->acceptDeviceName("Domyos-Bike", DeviceNameComparison::StartsWith)
        ->rejectDeviceName("DomyosBridge", DeviceNameComparison::StartsWith);


    // DomyosElliptical
    RegisterNewProductTestData(ProductIndex::DomyosElliptical)
        ->expectDevice<domyoselliptical>()        
        ->acceptDeviceName("Domyos-EL", DeviceNameComparison::StartsWith)
        ->rejectDeviceName("DomyosBridge",DeviceNameComparison::StartsWith);


    // Domyos rower
    RegisterNewProductTestData(ProductIndex::DomyosRower)
        ->expectDevice<domyosrower>()        
        ->acceptDeviceName("DOMYOS-ROW", DeviceNameComparison::StartsWithIgnoreCase)
        ->rejectDeviceName("DomyosBridge", DeviceNameComparison::StartsWith);


    // Domyos Treadmill
    QString ftms_Treadmill = "Domyos-Treadmill?"; // deliberately not all uppercase
    RegisterNewProductTestData(ProductIndex::DomyosTreadmill)
        ->expectDevice<domyostreadmill>()        
        ->acceptDeviceName("Domyos", DeviceNameComparison::StartsWith)
        ->rejectDeviceName("DomyosBr", DeviceNameComparison::StartsWith)
        ->rejectDeviceName("DOMYOS-BIKING-", DeviceNameComparison::StartsWith)
        ->rejectDeviceName(ftms_Treadmill.toUpper(), DeviceNameComparison::Exact)
        ->excluding<domyoselliptical>()
        ->excluding<domyosbike>()
        ->excluding<domyosrower>()
        ->excluding<horizontreadmill>()
        ->excluding<ftmsbike>()
        ->configureSettingsWith(QZSettings::ftms_treadmill, ftms_Treadmill,  "NOT "+ftms_Treadmill)
        ->configureBluetoothInfoWith(QBluetoothUuid((quint16)0x1826), false /*Should not be identified if it has 0x1826*/);
        // TODO: can't do BT config without settings config here

    // Echelon Connect Sport Bike
    RegisterNewProductTestData(ProductIndex::EchelonConnectSportBike)
        ->expectDevice<echelonconnectsport>()        
        ->acceptDeviceName("ECH", DeviceNameComparison::StartsWith)
        ->excluding<echelonrower>()
        ->excluding<echelonstride>();

    // Echelon Rower
    RegisterNewProductTestData(ProductIndex::EchelonRower)
        ->expectDevice<echelonrower>()        
        ->acceptDeviceName("ECH-ROW", DeviceNameComparison::StartsWith)
        ->acceptDeviceName("ROWSPORT-", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("ROW-S", DeviceNameComparison::StartsWith);


    // Echelon Stride Treadmill
    RegisterNewProductTestData(ProductIndex::EchelonStrideTreadmill)
        ->expectDevice<echelonstride>()        
        ->acceptDeviceName("ECH-STRIDE", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("ECH-UK-", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("ECH-SD-SPT", DeviceNameComparison::StartsWithIgnoreCase);


    // TODO: check if this is actually used
    // Elite Sterzo Smart
    RegisterNewProductTestData(ProductIndex::EliteSterzoSmart)
        ->expectDevice<elitesterzosmart>()
        ->disable("Unable to detect with current logic");


    // ES Linker Treadmill
    RegisterNewProductTestData(ProductIndex::ESLinkerTreadmill)
        ->expectDevice<eslinkertreadmill>()
        ->acceptDeviceName("ESLINKER", DeviceNameComparison::StartsWithIgnoreCase);


    // Fake Bike
    RegisterNewProductTestData(ProductIndex::FakeBike)
        ->expectDevice<fakebike>()        
        ->acceptDeviceName("", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::applewatch_fakedevice);


    // Fake Elliptical
    RegisterNewProductTestData(ProductIndex::FakeElliptical)
        ->expectDevice<fakeelliptical>()
        ->acceptDeviceName("", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::fakedevice_elliptical);


    // Fake Treadmill
    RegisterNewProductTestData(ProductIndex::FakeTreadmill)
        ->expectDevice<faketreadmill>()        
        ->acceptDeviceName("", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::fakedevice_treadmill);


    // FitPlus F5
    RegisterNewProductTestData(ProductIndex::FitPlusF5)
        ->expectDevice<fitplusbike>()        
        ->acceptDeviceName("FS-", DeviceNameComparison::StartsWith)
        ->configureSettingsWith( QZSettings::fitplus_bike);


    // FitPlus MRK
    RegisterNewProductTestData(ProductIndex::FitPlusBike_MRK_NoSettings)
        ->expectDevice<fitplusbike>()
        ->acceptDeviceName("MRK-", DeviceNameComparison::StartsWith)
        ->excluding<ftmsbike>()
        ->excluding<snodebike>();

    // FitShow FS
    RegisterNewProductTestData(ProductIndex::FitShowFS)
        ->expectDevice<fitshowtreadmill>()        
        ->acceptDeviceName("FS-", DeviceNameComparison::StartsWith)
        ->configureSettingsWith(
            [](const DeviceDiscoveryInfo& info, bool enable, std::vector<DeviceDiscoveryInfo>& configurations) -> void
            {
                DeviceDiscoveryInfo config(info);

                if(enable){
                    config.setValue(QZSettings::snode_bike, false);
                    config.setValue(QZSettings::fitplus_bike, false);
                    configurations.push_back(config);
                } else {
                    for(int i=1; i<4; i++) {
                        config.setValue(QZSettings::snode_bike, i&1);
                        config.setValue(QZSettings::fitplus_bike, i&2);
                        configurations.push_back(config);
                    }
                }
            })
        ->excluding<ftmsbike>();


    // FitShow SW
    RegisterNewProductTestData(ProductIndex::FitShowSW)
        ->expectDevice<fitshowtreadmill>()

        // SW, 14 characters total
        ->acceptDeviceName("SW345678901234", DeviceNameComparison::Exact)
        ->acceptDeviceName("SWFOURTEENCHAR", DeviceNameComparison::Exact)
        ->acceptDeviceName("WINFITA", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("NOBLEPRO CONNECT", DeviceNameComparison::StartsWithIgnoreCase)

        // too long and too short
        ->rejectDeviceName("SW3456789012345", DeviceNameComparison::Exact)
        ->rejectDeviceName("SW34567890123", DeviceNameComparison::Exact);


    // FitShow BF
    RegisterNewProductTestData(ProductIndex::FitShowBF)
        ->expectDevice<fitshowtreadmill>()
        ->acceptDeviceName("BF70", DeviceNameComparison::StartsWith);


    // Flywheel Bike
    RegisterNewProductTestData(ProductIndex::FlywheelBike)
        ->expectDevice<flywheelbike>()
        ->acceptDeviceName("Flywheel", DeviceNameComparison::StartsWith);


    // Flywheel Life Fitness IC8
    RegisterNewProductTestData(ProductIndex::FlywheelLifeFitnessIC8)
        ->expectDevice<flywheelbike>()        
        ->acceptDeviceName("BIKE", DeviceNameComparison::StartsWithIgnoreCase, 6)
        ->configureSettingsWith(QZSettings::flywheel_life_fitness_ic8);

    // Focus Treadmill
    RegisterNewProductTestData(ProductIndex::FocusTreadmill)
        ->expectDevice<focustreadmill>()
        ->acceptDeviceName("EW-TM-", DeviceNameComparison::StartsWithIgnoreCase);

    // FTMS Bike general
    auto ftmsBikeConfigureExclusions = {
        ProductTestDataIndex::GetTypeId<snodebike>(),
        ProductTestDataIndex::GetTypeId<fitplusbike>(),
        ProductTestDataIndex::GetTypeId<stagesbike>()
    };

    // FTMS Bike Hammer Racer S
    RegisterNewProductTestData(ProductIndex::FTMSBikeHammerRacerS)
        ->expectDevice<ftmsbike>()        
        ->acceptDeviceName("FS-", DeviceNameComparison::StartsWith)
        ->configureSettingsWith(QZSettings::hammer_racer_s)
        ->excluding(ftmsBikeConfigureExclusions);

    // FTMS Bike Hammer 64123
    RegisterNewProductTestData(ProductIndex::FTMSBikeHammer)
        ->expectDevice<ftmsbike>()
        ->acceptDeviceName("HAMMER ", DeviceNameComparison::StartsWith)
        ->configureSettingsWith(
            [](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations) -> void
            {
                DeviceDiscoveryInfo config(info);

                if (enable) {
                    config.setValue(QZSettings::power_sensor_as_bike, false);
                    config.setValue(QZSettings::saris_trainer, false);
                    configurations.push_back(config);
                } else {
                for(int x = 1; x<=3; x++) {
                    config.setValue(QZSettings::power_sensor_as_bike, x & 1);
                    config.setValue(QZSettings::saris_trainer, x & 2);
                    configurations.push_back(config);
                }

            }})
        ->excluding(ftmsBikeConfigureExclusions);

    // FTMS Bike IConsole
    RegisterNewProductTestData(ProductIndex::FTMSBikeIConsole)
        ->expectDevice<ftmsbike>()
        ->acceptDeviceName("ICONSOLE+", DeviceNameComparison::StartsWith)
        ->configureSettingsWith(QZSettings::toorx_ftms)
        ->excluding(ftmsBikeConfigureExclusions);


    // FTMS Bike
    QStringList acceptableFTMSNames {
        "DHZ-", // JK fitness 577
        "MKSM", // MKSM3600036
        "YS_C1_", // Yesoul C1H
        "YS_G1_", // Yesoul S3
        "YS_G1MPLUS", // Yesoul G1M Plus
        "DS25-", // Bodytone DS25
        "SCHWINN 510T",
        "3G CARDIO ",
        "ZWIFT HUB",
        "FLXCY-", // Pro FlexBike
        "QB-WC01", // Nexgim QB-C01 smart bike
        "XBR55",
        "ECHO_BIKE_",
        "EW-JS-",
        "MERACH-MR667-",
        "DS60-",
        "BIKE-",
        "SPAX-BK-",
        "YSV1",
        "CECOTEC", // Cecotec DrumFit Indoor 10000 MagnoMotor Connected #2420
        "WATTBIKE",
        "ZYCLEZBIKE",
        "WAVEFIT-",
        "KETTLERBLE",
        "JAS_C3",
        "RAVE WHITE",
        "DOMYOS-BIKING-",
        "DU30-",
        "BIKZU_",
        "WLT8828",
        "VANRYSEL-HT",
        "HARISON-X15",
        "FEIVON V2",
        "FELVON V2",
        "ZUMO",
        "XS08-",
        "B94",
        "STAGES BIKE",
        "SUITO",
        "D2RIDE",
        "DIRETO X",
        "MERACH-667-",
        "SMB1",
        "UBIKE FTMS",
        "INRIDE"
    };
    RegisterNewProductTestData(ProductIndex::FTMSBike)
        ->expectDevice<ftmsbike>()
        ->acceptDeviceNames(acceptableFTMSNames, DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("DI", DeviceNameComparison::StartsWithIgnoreCase, 2) // Elite smart trainer #1682)
        ->acceptDeviceName("YSV", DeviceNameComparison::StartsWithIgnoreCase, 9) // YSV100783
        ->acceptDeviceName("URSB", DeviceNameComparison::StartsWithIgnoreCase, 7) // URSB005
        ->acceptDeviceName("DBF", DeviceNameComparison::StartsWithIgnoreCase, 6) // DBF135
        ->acceptDeviceName("KSU", DeviceNameComparison::StartsWithIgnoreCase, 7) // KSU1102
        ->acceptDeviceName("VOLT", DeviceNameComparison::StartsWithIgnoreCase, 4)
        ->acceptDeviceName("F","ARROW",DeviceNameComparison::Exact) // FI9110 Arrow, https://www.fitnessdigital.it/bicicletta-smart-bike-ion-fitness-arrow-connect/p/10022863/ IO Fitness Arrow
        ->acceptDeviceName("ICSE", DeviceNameComparison::StartsWithIgnoreCase, 4)
        ->acceptDeviceName("FLX", DeviceNameComparison::StartsWithIgnoreCase, 10)
        ->acceptDeviceName("CSRB", DeviceNameComparison::StartsWithIgnoreCase, 11)


        // Starts with DT- and is 14+ characters long.
        // TODO: update once addDeviceName can generate valid and invalid names for variable length patterns

        ->acceptDeviceName("DT-0123456789A", DeviceNameComparison::IgnoreCase) // Sole SB700
        ->acceptDeviceName("DT-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", DeviceNameComparison::IgnoreCase) // Sole SB700
        ->rejectDeviceName("DT-0123456789", DeviceNameComparison::IgnoreCase) // too short for Sole SB700
        ->rejectDeviceName("DBF13", DeviceNameComparison::IgnoreCase) // too short for DBF135
        ->rejectDeviceName("DBF1355", DeviceNameComparison::IgnoreCase) // too long for DBF135

        ->excluding(ftmsBikeConfigureExclusions);

    // FTMS Accessory
    QString ftmsAccessoryName = "accessory";
    RegisterNewProductTestData(ProductIndex::FTMSAccessory)
        ->expectDevice<ftmsbike>()        
        ->acceptDeviceName(ftmsAccessoryName, DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(
            [ftmsAccessoryName](DeviceDiscoveryInfo& info, bool enable)->void
            {
                info.setValue(QZSettings::ss2k_peloton, enable);
                info.setValue(QZSettings::ftms_accessory_name, enable ? ftmsAccessoryName : "NOT " + ftmsAccessoryName );
            })
        ->excluding(ftmsBikeConfigureExclusions);


    // FTMS KICKR CORE
    RegisterNewProductTestData(ProductIndex::FTMSKICKRCORE)
        ->expectDevice<ftmsbike>()        
        ->acceptDeviceName("KICKR CORE", DeviceNameComparison::StartsWithIgnoreCase)
        ->excluding(ftmsBikeConfigureExclusions)
        ->configureBluetoothInfoWith(QBluetoothUuid((quint16)0x1826));

    // FTMS Bike 2
    RegisterNewProductTestData(ProductIndex::FTMSBike2)
        ->expectDevice<ftmsbike>()
        ->acceptDeviceNames({"GLT",
                             "SPORT01-"}, // Labgrey Magnetic Exercise Bike https://www.amazon.co.uk/dp/B0CXMF1NPY?_encoding=UTF8&psc=1&ref=cm_sw_r_cp_ud_dp_PE420HA7RD7WJBZPN075&ref_=cm_sw_r_cp_ud_dp_PE420HA7RD7WJBZPN075&social_share=cm_sw_r_cp_ud_dp_PE420HA7RD7WJBZPN075&skipTwisterOG=1,
                            DeviceNameComparison::StartsWithIgnoreCase)
        ->excluding(ftmsBikeConfigureExclusions)
        ->configureBluetoothInfoWith(QBluetoothUuid((quint16)0x1826));

    // FTMS Rower
    RegisterNewProductTestData(ProductIndex::FTMSRower)
        ->expectDevice<ftmsrower>()        
        ->acceptDeviceName("CR 00", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KAYAKPRO", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("WHIPR", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KS-WLT", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("I-ROWER", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("PM5ROW", DeviceNameComparison::IgnoreCase)
        ->acceptDeviceName("PM5XROW", DeviceNameComparison::IgnoreCase)
        ->acceptDeviceName("SF-RW", DeviceNameComparison::IgnoreCase)
        ->acceptDeviceName("S4 COMMS", DeviceNameComparison::StartsWithIgnoreCase);


    // Horizon GR7 Bike
    RegisterNewProductTestData(ProductIndex::HorizonGR7Bike)
        ->expectDevice<horizongr7bike>()
        ->acceptDeviceName("JFIC", DeviceNameComparison::StartsWithIgnoreCase);


    // Horizon Treadmill
    RegisterNewProductTestData(ProductIndex::HorizonTreadmill)
        ->expectDevice<horizontreadmill>()        
        ->acceptDeviceName("HORIZON", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("AFG SPORT", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("WLT2541", DeviceNameComparison::StartsWithIgnoreCase)

        // FTMS
        ->acceptDeviceName("T318_", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("T218_", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("TRX3500", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("JFTMPARAGON", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("PARAGON X", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("JFTM", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("CT800", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("MOBVOI TM", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("DK202000725", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("CTM780102C6BB32D62", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("MX-TM ", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("MATRIXTF50", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("MOBVOI TM", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KETTLER TREADMILL", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("ASSAULTRUNNER", DeviceNameComparison::StartsWithIgnoreCase);


    // Horizon Treadmill (Toorx)
    RegisterNewProductTestData(ProductIndex::HorizonTreadmill_Toorx)
        ->expectDevice<horizontreadmill>()        
        ->acceptDeviceName("TOORX", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("I-CONSOLE+", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(
            [](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations) -> void
            {
                DeviceDiscoveryInfo config(info);

                if (enable) {
                    config.setValue(QZSettings::toorx_ftms_treadmill, true);
                    config.setValue(QZSettings::toorx_ftms, false);
                    configurations.push_back(config);
                } else {
                    // Basic case where the device is disabled in the settings
                    config.setValue(QZSettings::toorx_ftms_treadmill, false);
                    config.setValue(QZSettings::toorx_ftms, false);
                    configurations.push_back(config);

                    // Basic case where the device is disabled in the settings and has an excluding settings
                    config.setValue(QZSettings::toorx_ftms_treadmill, false);
                    config.setValue(QZSettings::toorx_ftms, true);
                    configurations.push_back(config);

                    // Enabled in settings, but with excluding setting
                    config.setValue(QZSettings::toorx_ftms_treadmill, true);
                    config.setValue(QZSettings::toorx_ftms, true);
                    configurations.push_back(config);
                }
            });


    // Horizon Treadmill (Bodytone)
    RegisterNewProductTestData(ProductIndex::HorizonTreadmill_Bodytone)
        ->expectDevice<horizontreadmill>()        
        ->acceptDeviceName("TF-", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::horizon_treadmill_force_ftms);

    // Horizon Treadmill (Domyos TC)
    RegisterNewProductTestData(ProductIndex::HorizonTreadmill_DomyosTC)
        ->expectDevice<horizontreadmill>()        
        ->acceptDeviceName("DOMYOS-TC", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::domyostreadmill_notfmts, false)
        ->configureBluetoothInfoWith(QBluetoothUuid((quint16)0x1826));

    // iConcept Bike
    RegisterNewProductTestData(ProductIndex::iConceptBike)
        ->expectDevice<iconceptbike>()
        ->acceptDeviceName("BH DUALKIT", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::iconcept_elliptical, false);

    // iConcept Elliptical
    RegisterNewProductTestData(ProductIndex::iConceptElliptical)
        ->expectDevice<iconceptelliptical>()        
        ->acceptDeviceName("BH DUALKIT", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::iconcept_elliptical);


    // Inspire Bike
    RegisterNewProductTestData(ProductIndex::InspireBike)
        ->expectDevice<inspirebike>()
        ->acceptDeviceName("IC", DeviceNameComparison::StartsWithIgnoreCase, 8);

    // Keep Bike
    RegisterNewProductTestData(ProductIndex::KeepBike)
        ->expectDevice<keepbike>()
        ->acceptDeviceName("KEEP_BIKE_", DeviceNameComparison::StartsWithIgnoreCase);


    // Kingsmith R1 Pro Treadmill
    RegisterNewProductTestData(ProductIndex::KingsmithR1ProTreadmill)
        ->expectDevice<kingsmithr1protreadmill>()        
        ->acceptDeviceName("R1 PRO", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("RE", DeviceNameComparison::IgnoreCase)
        ->acceptDeviceName("KINGSMITH", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KS-H", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("DYNAMAX", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("WALKINGPAD", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KS-BLR", DeviceNameComparison::StartsWithIgnoreCase)
        ->excluding<kingsmithr2treadmill>();


    // Kingsmith R2 Treadmill
    RegisterNewProductTestData(ProductIndex::KingsmithR2Treadmill)
        ->expectDevice<kingsmithr2treadmill>()        
        ->acceptDeviceName("KS-ST-K12PRO", DeviceNameComparison::StartsWithIgnoreCase)

        // KingSmith Walking Pad R2
        ->acceptDeviceName("KS-R1AC", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KS-HC-R1AA", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KS-HC-R1AC", DeviceNameComparison::StartsWithIgnoreCase)

        // KingSmith Walking Pad X21
        ->acceptDeviceName("KS-X21", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KS-HDSC-X21C", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KS-HDSY-X21C", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KS-NGCH-X21C", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KS-NACH-X21C", DeviceNameComparison::StartsWithIgnoreCase)

        // KingSmith Walking Pad G1
        ->acceptDeviceName("KS-NGCH-G1C", DeviceNameComparison::StartsWithIgnoreCase);

    // Life Fitness Treadmill
    RegisterNewProductTestData(ProductIndex::LifeFitnessTreadmill)
        ->expectDevice<lifefitnesstreadmill>()
        ->acceptDeviceName("LF", DeviceNameComparison::StartsWithIgnoreCase, 18);


    // M3I Bike
    RegisterNewProductTestData(ProductIndex::M3IBike)
        ->expectDevice<m3ibike>()
        ->acceptDeviceName("M3", DeviceNameComparison::StartsWith)
        ->configureBluetoothInfoWith(
            [](const QBluetoothDeviceInfo& info,  bool enable, std::vector<QBluetoothDeviceInfo>& bluetoothDeviceInfos)->void
            {
                // The M3I bike detector looks into the manufacturer data.
                QBluetoothDeviceInfo result = info;

                if(!enable) {
                    result.setManufacturerData(1, QByteArray("Invalid manufacturer data."));
                    bluetoothDeviceInfos.push_back(result);

                    return;
                }

                int key=0;
                result.setManufacturerData(key++, hex2bytes("02010639009F00000000000000000014008001"));

                /*
    // more data that has been supplied
    result.setManufacturerData(key++, hex2bytes("02010639009F00000000000000000014008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBA000000020000000014008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBA000000020000000013008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBA000000020000000013008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBA000000020000000012008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBA000000020000000012008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBA000000000000000011008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBC000000020000000010008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBC000000020000000010008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBC00000002000000000F008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBC00000002000000000F008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBC00000002000000000E008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FBC00000002000000000E008001"));
    result.setManufacturerData(key++, hex2bytes("02010639009F0000000003000000000C000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FDD00000003000000000C000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FDD00000003000000000C000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FDD00000003000000000B000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FDD00000003000000000B000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FDD00000003000000000B000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FDD00000003000000000A000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FDD00000003000000000A000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009F0000000000000000000A000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FE8000000030000000009000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FE8000000030000000009000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FE8000000030000000009000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FE8000000030000000008000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FE8000000030000000008000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FE8000000030000000008000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FE8000000030000000007000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FE8000000030000000000000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FD3000000030000000000000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FD3000000030000000000000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FD3000000030000000000000001"));
    result.setManufacturerData(key++, hex2bytes("02010639009FD3000000030000000000000001"));
    */

                bluetoothDeviceInfos.push_back(result);
            });


    // MCF Bike
    RegisterNewProductTestData(ProductIndex::MCFBike)
        ->expectDevice<mcfbike>()
        ->acceptDeviceName("MCF-", DeviceNameComparison::StartsWithIgnoreCase);


    // Mepanel Bike
    RegisterNewProductTestData(ProductIndex::MepanelBike)
        ->expectDevice<mepanelbike>()
        ->acceptDeviceName("MEPANEL", DeviceNameComparison::StartsWithIgnoreCase);


    // Nautilus Bike
    RegisterNewProductTestData(ProductIndex::NautilusBike)
        ->expectDevice<nautilusbike>()
        ->acceptDeviceName("NAUTILUS B", DeviceNameComparison::StartsWithIgnoreCase);


    // Nautilus Elliptical
    RegisterNewProductTestData(ProductIndex::NautilusElliptical)
        ->expectDevice<nautiluselliptical>()
        ->acceptDeviceName("NAUTILUS E", DeviceNameComparison::StartsWithIgnoreCase);


    // Nautilus Treadmill
    RegisterNewProductTestData(ProductIndex::NautilusTreadmill)
        ->expectDevice<nautilustreadmill>()
        ->acceptDeviceName("NAUTILUS T", DeviceNameComparison::StartsWithIgnoreCase);


    // Norditrack Elliptical
    RegisterNewProductTestData(ProductIndex::NorditrackElliptical)
        ->expectDevice<nordictrackelliptical>()
        ->acceptDeviceName("I_EL", DeviceNameComparison::StartsWithIgnoreCase);


    // Nordictrack IFit ADB Treadmill
    RegisterNewProductTestData(ProductIndex::NordictrackIFitADBTreadmill)
        ->expectDevice<nordictrackifitadbtreadmill>()        
        ->acceptDeviceName("", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::nordictrack_2950_ip, testIP, "");

    // NPE Cable Bike
    RegisterNewProductTestData(ProductIndex::NPECableBike)
        ->expectDevice<npecablebike>()
        ->acceptDeviceName(">CABLE", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("MD", DeviceNameComparison::StartsWithIgnoreCase, 7)
        ->configureSettingsWith(QZSettings::flywheel_life_fitness_ic8, false);

    // NPE Cable Bike
    RegisterNewProductTestData(ProductIndex::NPECableBike)
        ->expectDevice<npecablebike>()
        ->acceptDeviceName(">CABLE", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("MD", DeviceNameComparison::StartsWithIgnoreCase, 7);


    // NPE Cable Bike (excluding Flywheel Life Fitness IC8)
    RegisterNewProductTestData(ProductIndex::NPECableBike_Excluding_FlywheelLifeFitnessIC8)
        ->expectDevice<npecablebike>()

        // BIKE 1, BIKE 2, BIKE 3...
        ->acceptDeviceName("BIKE", DeviceNameComparison::StartsWithIgnoreCase, 6)

        // put in a name that's too long.
        ->rejectDeviceName("BIKE567", DeviceNameComparison::IgnoreCase)

        ->configureSettingsWith(QZSettings::flywheel_life_fitness_ic8, false /* don't allow this device if the Flywheel bike is enabled. */);

    // Octane Elliptical
    RegisterNewProductTestData(ProductIndex::OctaneElliptical)
        ->expectDevice<octaneelliptical>()
        ->acceptDeviceName("Q37", DeviceNameComparison::StartsWithIgnoreCase);


    // Octane Elliptical
    RegisterNewProductTestData(ProductIndex::OctaneTreadmill)
        ->expectDevice<octanetreadmill>()        
        ->acceptDeviceName("ZR7", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("ZR8", DeviceNameComparison::StartsWithIgnoreCase);


    // Pafers Bike
    RegisterNewProductTestData(ProductIndex::PafersBike)
        ->expectDevice<pafersbike>()
        ->acceptDeviceName("PAFERS_", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::pafers_treadmill,false);

    // Pafers Treadmill
    RegisterNewProductTestData(ProductIndex::PafersTreadmill)
        ->expectDevice<paferstreadmill>()
        ->acceptDeviceName("PAFERS_", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith( [](const DeviceDiscoveryInfo& info, bool enable, std::vector<DeviceDiscoveryInfo>& configurations)->void {
            DeviceDiscoveryInfo config(info);

            if (enable) {
                for(int x = 1; x<=3; x++) {
                    config.setValue(QZSettings::pafers_treadmill, x & 1);
                    config.setValue(QZSettings::pafers_treadmill_bh_iboxster_plus, x & 2);
                    configurations.push_back(config);
                }
            } else {
                config.setValue(QZSettings::pafers_treadmill, false);
                config.setValue(QZSettings::pafers_treadmill_bh_iboxster_plus, false);
                configurations.push_back(config);
            }
        });


    // Proform Bike
    RegisterNewProductTestData(ProductIndex::ProformBike)
        ->expectDevice<proformbike>()        
        ->acceptDeviceName("I_EB", DeviceNameComparison::StartsWith)
        ->acceptDeviceName("I_SB", DeviceNameComparison::StartsWith);

    // Proform Elliptical
    RegisterNewProductTestData(ProductIndex::ProformElliptical)
        ->expectDevice<proformelliptical>()
        ->acceptDeviceName("I_FS", DeviceNameComparison::StartsWithIgnoreCase);

    // Proform Elliptical Trainer
    RegisterNewProductTestData(ProductIndex::ProformEllipticalTrainer)
        ->expectDevice<proformellipticaltrainer>()
        ->acceptDeviceName("I_VE", DeviceNameComparison::StartsWithIgnoreCase);

    // Proform Rower
    RegisterNewProductTestData(ProductIndex::ProFormRower)
        ->expectDevice<proformrower>()
        ->acceptDeviceName("I_RW", DeviceNameComparison::StartsWithIgnoreCase);

    // Proform Treadmill
    RegisterNewProductTestData(ProductIndex::ProFormTreadmill)
        ->expectDevice<proformtreadmill>()
        ->acceptDeviceName("I_TL", DeviceNameComparison::StartsWith);

    // ProForm Wifi Bike
    RegisterNewProductTestData(ProductIndex::ProFormWifiBike)
        ->expectDevice<proformwifibike>()        
        ->acceptDeviceName("", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::proformtdf4ip, testIP, "");

    // ProForm Wifi Treadmill
    RegisterNewProductTestData(ProductIndex::ProFormWifiTreadmill)
        ->expectDevice<proformwifitreadmill>()        
        ->acceptDeviceName("", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::proformtreadmillip, testIP, "");

    // Renpho Bike General
    auto renphoBikeExclusions = {
        GetTypeId<fitplusbike>(),
        GetTypeId<snodebike>()
    };

    // Renpho Bike
    RegisterNewProductTestData(ProductIndex::RenphoBike)
        ->expectDevice<renphobike>()
        ->acceptDeviceName("RQ", DeviceNameComparison::StartsWithIgnoreCase, 5)
        ->acceptDeviceName("SCH130", DeviceNameComparison::StartsWithIgnoreCase)
        ->excluding(renphoBikeExclusions);

    // Renpho Bike
    RegisterNewProductTestData(ProductIndex::RenphoBike2)
        ->expectDevice<renphobike>()
        // TODO: generate valid/invalid names for a minimum length
        ->acceptDeviceName("R-Q", DeviceNameComparison::StartsWithIgnoreCase,7)
        ->acceptDeviceName("R-Q12345678910", DeviceNameComparison::StartsWithIgnoreCase)
        ->rejectDeviceName("R-Q123", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::power_sensor_as_bike, false)
        ->excluding(renphoBikeExclusions);

    // Renpho Bike (Toorx FTMS)
    RegisterNewProductTestData(ProductIndex::RenphoBike_ToorxFTMS)
        ->expectDevice<renphobike>()
        ->acceptDeviceName("TOORX", DeviceNameComparison::StartsWith)
        ->configureSettingsWith(
            [](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations) -> void
            {
                DeviceDiscoveryInfo config(info);

                config.setValue(QZSettings::toorx_ftms, enable);
                config.setValue(QZSettings::toorx_bike, true);
                configurations.push_back(config);
                config.setValue(QZSettings::toorx_ftms, enable);
                config.setValue(QZSettings::toorx_bike, false);
                configurations.push_back(config);
            })
        ->excluding(renphoBikeExclusions);


    // Schwinn 170 Bike
    RegisterNewProductTestData(ProductIndex::Schwinn170Bike)
        ->expectDevice<schwinn170bike>()        
        ->acceptDeviceName("SCHWINN 170/270", DeviceNameComparison::StartsWithIgnoreCase);


    // Schwinn IC4 Bike
    RegisterNewProductTestData(ProductIndex::SchwinnIC4Bike)
        ->expectDevice<schwinnic4bike>()        
        ->acceptDeviceName("IC BIKE", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("C7-", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("C9/C10", DeviceNameComparison::StartsWithIgnoreCase)

        // 17 characters, beginning with C7-
        ->rejectDeviceName("C7-45678901234567", DeviceNameComparison::IgnoreCase);;


    // Shuaa5 Treadmill
    RegisterNewProductTestData(ProductIndex::Shuaa5Treadmill)
        ->expectDevice<shuaa5treadmill>()
        ->acceptDeviceName("ZW-", DeviceNameComparison::StartsWithIgnoreCase);


    // Skandika Wiry Bike
    RegisterNewProductTestData(ProductIndex::SkandikaWiryBike)
        ->expectDevice<skandikawiribike>()        
        ->acceptDeviceName("BFCP", DeviceNameComparison::StartsWithIgnoreCase);


    // Smart Row Rower
    RegisterNewProductTestData(ProductIndex::SmartRowRower)
        ->expectDevice<smartrowrower>()        
        ->acceptDeviceName("SMARTROW", DeviceNameComparison::StartsWithIgnoreCase);

    // Snode Bike General
    auto snodeBikeExclusions = {
        GetTypeId<fitplusbike>(),
        GetTypeId<ftmsbike>()
    };

    // Snode Bike FS
    RegisterNewProductTestData(ProductIndex::SnodeBikeFS)
        ->expectDevice<snodebike>()
        ->acceptDeviceName("FS-", DeviceNameComparison::StartsWith)
        ->configureSettingsWith(QZSettings::snode_bike)
        ->excluding(snodeBikeExclusions);

    // Snode Bike TF
    RegisterNewProductTestData(ProductIndex::SnodeBikeTF)
        ->expectDevice<snodebike>()        
        ->acceptDeviceName("TF-", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::horizon_treadmill_force_ftms, false)
        ->excluding(snodeBikeExclusions);


    // Sole Bike
    RegisterNewProductTestData(ProductIndex::SoleBike)
        ->expectDevice<solebike>()        
        ->acceptDeviceName("LCB", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("R92", DeviceNameComparison::StartsWithIgnoreCase);


    // Sole Elliptical
    RegisterNewProductTestData(ProductIndex::SoleElliptical)
        ->expectDevice<soleelliptical>()        
        ->acceptDeviceName("E95S", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("E25", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("E35", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("E55", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("E95", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("E98", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("XG400", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("E98S", DeviceNameComparison::StartsWithIgnoreCase);


    // Sole F80 Treadmill
    RegisterNewProductTestData(ProductIndex::SoleF80Treadmill)
        ->expectDevice<solef80treadmill>()        
        ->acceptDeviceName("F65", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("S77", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("TT8", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("F63", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("ST90", DeviceNameComparison::StartsWithIgnoreCase);


    // Sole F85 Treadmill
    RegisterNewProductTestData(ProductIndex::SoleF85Treadmill)
        ->expectDevice<solef80treadmill>()        
        ->acceptDeviceName("F85", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("F89", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("F80", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::sole_treadmill_inclination);


    // Spirit Treadmill
    RegisterNewProductTestData(ProductIndex::SpiritTreadmill)
        ->expectDevice<spirittreadmill>()        
        ->acceptDeviceName("XT385", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("XT485", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("XT800", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("XT900", DeviceNameComparison::StartsWithIgnoreCase);


    // Sports Plus Bike
    RegisterNewProductTestData(ProductIndex::SportsPlusBike)
        ->expectDevice<sportsplusbike>()        
        ->acceptDeviceName("CARDIOFIT", DeviceNameComparison::StartsWithIgnoreCase);


    // Sports Tech Bike
    RegisterNewProductTestData(ProductIndex::SportsTechBike)
        ->expectDevice<sportstechbike>()        
        ->acceptDeviceName("EW-BK", DeviceNameComparison::StartsWithIgnoreCase);


    // Stages Bike General
    auto stagesBikeExclusions = { GetTypeId<ftmsbike>() };

    // Stages Bike
    RegisterNewProductTestData(ProductIndex::StagesBike)
        ->expectDevice<stagesbike>()        
        ->acceptDeviceName("STAGES ", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("TACX SATORI", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("QD", DeviceNameComparison::IgnoreCase)
        ->excluding(stagesBikeExclusions);


    // Stages Bike Stages Bike (Assioma / Power Sensor disabled
    RegisterNewProductTestData(ProductIndex::StagesBike_Assioma_PowerSensorDisabled)
        ->expectDevice<stagesbike>()        
        ->acceptDeviceName("ASSIOMA", DeviceNameComparison::StartsWithIgnoreCase)
        ->excluding( stagesBikeExclusions);

    // Stages Bike (KICKR CORE)
    RegisterNewProductTestData(ProductIndex::StagesBike_KICKRCORE)
        ->expectDevice<stagesbike>()        
        ->acceptDeviceName("KICKR CORE", DeviceNameComparison::StartsWithIgnoreCase)
        ->excluding(stagesBikeExclusions)
        ->configureBluetoothInfoWith(
            [](const QBluetoothDeviceInfo& info,  bool enable, std::vector<QBluetoothDeviceInfo>& bluetoothDeviceInfos)->void
            {
                // The condition, if the name is acceptable, is:
                // !deviceHasService(b, QBluetoothUuid((quint16)0x1826)) && deviceHasService(b, QBluetoothUuid((quint16)0x1818)))

                if(enable) {
                    QBluetoothDeviceInfo result = info;
                    result.setServiceUuids(QVector<QBluetoothUuid>({QBluetoothUuid((quint16)0x1818)}));
                    bluetoothDeviceInfos.push_back(result);
                } else {
                    QBluetoothDeviceInfo hasInvalid = info;
                    hasInvalid.setServiceUuids(QVector<QBluetoothUuid>({QBluetoothUuid((quint16)0x1826)}));
                    QBluetoothDeviceInfo hasBoth = hasInvalid;
                    hasBoth.setServiceUuids(QVector<QBluetoothUuid>({QBluetoothUuid((quint16)0x1818),QBluetoothUuid((quint16)0x1826)}));

                    bluetoothDeviceInfos.push_back(info); // has neither
                    bluetoothDeviceInfos.push_back(hasInvalid);
                    bluetoothDeviceInfos.push_back(hasBoth);
                }
            });



    // StrydeRun Power Sensor
    QString powerSensorName = "WattsItCalled";
    RegisterNewProductTestData(ProductIndex::StrydeRunTreadmill_PowerSensor)
        ->expectDevice<strydrunpowersensor>()        
        ->acceptDeviceName(powerSensorName, DeviceNameComparison::StartsWith)
        ->configureSettingsWith(
            [powerSensorName](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations) -> void
            {
                if(enable) {
                    // power_as_treadmill enabled and powerSensorName in settings matches device name
                    DeviceDiscoveryInfo config(info);
                    config.setValue(QZSettings::power_sensor_as_treadmill, true);
                    config.setValue(QZSettings::power_sensor_name, powerSensorName);
                    configurations.push_back(config);
                } else {
                    // enabled but powerSensorName in settings does not match device name
                    DeviceDiscoveryInfo config(info);
                    config.setValue(QZSettings::power_sensor_as_treadmill, true);
                    config.setValue(QZSettings::power_sensor_name, "NOT " + powerSensorName);
                    configurations.push_back(config);

                    // disabled with non-matching name
                    config.setValue(QZSettings::power_sensor_as_treadmill, false);
                    config.setValue(QZSettings::power_sensor_name, "NOT " + powerSensorName);
                    configurations.push_back(config);

                    // disabled with matching name
                    config.setValue(QZSettings::power_sensor_as_treadmill, false);
                    config.setValue(QZSettings::power_sensor_name, powerSensorName);
                    configurations.push_back(config);
                }
            });


    // Tacx Neo 2 Bike
    RegisterNewProductTestData(ProductIndex::TacxNeo2Bike)
        ->expectDevice<tacxneo2>()        
        ->acceptDeviceName("TACX NEO", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("TACX FLOW", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("TACX SMART BIKE", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("THINK X", DeviceNameComparison::StartsWithIgnoreCase);


    // TechnoGym MyRun Treadmill
    RegisterNewProductTestData(ProductIndex::TechnoGymMyRunTreadmill)
        ->expectDevice<technogymmyruntreadmill>()        
        ->acceptDeviceName("MYRUN ", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("MERACH-U3", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::technogym_myrun_treadmill_experimental, false);


    // TechnoGym MyRun Treadmill RF Comm
    RegisterNewProductTestData(ProductIndex::TechnoGymMyRunTreadmillRFComm)
        ->expectDevice<technogymmyruntreadmillrfcomm>()        
        ->acceptDeviceName("MYRUN ", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("MERACH-U3", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(QZSettings::technogym_myrun_treadmill_experimental);


    // Toorx Treadmill
    RegisterNewProductTestData(ProductIndex::ToorxTreadmill)
        ->expectDevice<toorxtreadmill>()        
        ->acceptDeviceName("TRX ROUTE KEY", DeviceNameComparison::StartsWith);


    // True Treadmill
    RegisterNewProductTestData(ProductIndex::TrueTreadmill)
        ->expectDevice<truetreadmill>()        
        ->acceptDeviceName("TRUE", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("TREADMILL", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("ASSAULT TREADMILL ", DeviceNameComparison::StartsWithIgnoreCase);



    // Toorx AppGate USB Bike General
    auto toorxAppGateUSBBikeExclusions ={ GetTypeId<trxappgateusbtreadmill>() };

    // Toorx AppGate USB Bike
    RegisterNewProductTestData(ProductIndex::ToorxAppGateUSBBike)
        ->expectDevice<trxappgateusbbike>()        
        ->acceptDeviceName("TUN ", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("PASYOU-", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(
            [](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations) -> void
            {
                // This particular case of TrxAppGateUSBBike is independent of the setting

                DeviceDiscoveryInfo config(info);
                config.setValue(QZSettings::toorx_bike, true);
                config.setValue(QZSettings::toorx_ftms_treadmill, !enable);
                configurations.push_back(config);

                config.setValue(QZSettings::toorx_bike, false);
                config.setValue(QZSettings::toorx_ftms_treadmill, !enable);
                configurations.push_back(config);
            })
        ->excluding(toorxAppGateUSBBikeExclusions);


    // Toorx AppGate USB Bike (Enabled in settings)
    RegisterNewProductTestData(ProductIndex::ToorxAppGateUSBBike_EnabledInSettings)
        ->expectDevice<trxappgateusbbike>()        
        ->acceptDeviceName("TOORX", DeviceNameComparison::StartsWith)
        ->acceptDeviceName("I-CONSOIE+", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("I-CONSOLE+", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("IBIKING+", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("ICONSOLE+", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("VIFHTR2.1", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("DKN MOTION", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("CR011R", DeviceNameComparison::IgnoreCase)
        ->configureSettingsWith(
            [](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations) -> void
            {
                DeviceDiscoveryInfo config(info);

                if(enable) {
                    config.setValue(QZSettings::toorx_bike, true);
                    config.setValue(QZSettings::toorx_ftms_treadmill, false);
                    configurations.push_back(config);
                } else {
                    config.setValue(QZSettings::toorx_bike, false);
                    config.setValue(QZSettings::toorx_ftms_treadmill, true);
                    configurations.push_back(config);
                    config.setValue(QZSettings::toorx_bike, false);
                    config.setValue(QZSettings::toorx_ftms_treadmill, false);
                    configurations.push_back(config);
                }
            })
        ->excluding(toorxAppGateUSBBikeExclusions);


    // TrxAppGateUSB Elliptical
    RegisterNewProductTestData(ProductIndex::TrxAppGateUSBElliptical)
        ->expectDevice<trxappgateusbelliptical>()        
        ->acceptDeviceName("FAL-SPORTS", DeviceNameComparison::StartsWithIgnoreCase)
        // TODO: deal with I-CONSOLE+
        ->excluding(toorxAppGateUSBBikeExclusions)
        ->configureSettingsWith(
            [](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations) -> void
            {
                DeviceDiscoveryInfo config(info);
                if(enable) {
                    config.setValue(QZSettings::ftms_bike, QZSettings::default_ftms_bike);
                    configurations.push_back(config);
                    config.setValue(QZSettings::ftms_bike, "X"+QZSettings::default_ftms_bike+"X");
                    configurations.push_back(config);
                } else {
                    config.setValue(QZSettings::ftms_bike, "PLACEHOLDER");
                    configurations.push_back(config);
                }
            }) ;


    // Toorx AppGate USB Treadmill
    RegisterNewProductTestData(ProductIndex::ToorxAppGateUSBTreadmill)
        ->expectDevice<trxappgateusbtreadmill>()        
        ->acceptDeviceName("TOORX", DeviceNameComparison::StartsWith)
        ->acceptDeviceName("V-RUN", DeviceNameComparison::StartsWith)
        ->acceptDeviceName("K80_", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("I-CONSOLE+", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("ICONSOLE+", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("I-RUNNING", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("DKN RUN", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("REEBOK", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith([](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations) -> void
                                {
                                    DeviceDiscoveryInfo config(info);

                                    if(enable) {
                                        config.setValue(QZSettings::toorx_bike, false);
                                        config.setValue(QZSettings::toorx_ftms_treadmill, false);
                                        configurations.push_back(config);
                                    } else {
                                        for(int i=1; i<4; i++) {
                                            config.setValue(QZSettings::toorx_bike, i&1);
                                            config.setValue(QZSettings::toorx_ftms_treadmill, i&2);
                                            configurations.push_back(config);
                                        }
                                    }
                                })
        ->excluding<trxappgateusbbike>();

    // Ultrasport Bike
    RegisterNewProductTestData(ProductIndex::UltrasportBike)
        ->expectDevice<ultrasportbike>()
        ->acceptDeviceName("X-BIKE", DeviceNameComparison::StartsWithIgnoreCase);


    // Wahoo Kickr Snap Bike
    RegisterNewProductTestData(ProductIndex::WahooKickrSnapBike)
        ->expectDevice<wahookickrsnapbike>()        
        ->acceptDeviceName("KICKR SNAP", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KICKR BIKE", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("KICKR ROLLR", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("WAHOO KICKR", DeviceNameComparison::StartsWithIgnoreCase)
        ->excluding<ftmsbike>();

    // Yesoul Bike
    RegisterNewProductTestData(ProductIndex::YesoulBike)
        ->expectDevice<yesoulbike>()        
        ->acceptDeviceName(yesoulbike::bluetoothName, DeviceNameComparison::StartsWith);


    // Ypoo Elliptical
    RegisterNewProductTestData(ProductIndex::YpooElliptical)
        ->expectDevice<ypooelliptical>()        
        ->acceptDeviceName("YPOO-U3-", DeviceNameComparison::StartsWithIgnoreCase)
        ->acceptDeviceName("SCH_590E", DeviceNameComparison::StartsWithIgnoreCase);


    // Zipro Treadmill
    RegisterNewProductTestData(ProductIndex::ZiproTreadmill)
        ->expectDevice<ziprotreadmill>()
        ->acceptDeviceName("RZ_TREADMIL", DeviceNameComparison::StartsWithIgnoreCase);


    // Zwift Runpod
    QString zwiftRunPodPowerSensorName = "WattsItCalled";
    RegisterNewProductTestData(ProductIndex::ZwiftRunpod)
        ->expectDevice<strydrunpowersensor>()        
        ->acceptDeviceName("ZWIFT RUNPOD", DeviceNameComparison::StartsWithIgnoreCase)
        ->configureSettingsWith(
            [zwiftRunPodPowerSensorName](const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations) -> void
            {
                DeviceDiscoveryInfo config(info);

                if(enable) {
                    /* Avoid the config that enables the StrydeRunPowerSensorTestData device
                    // power_as_treadmill enabled and powerSensorName in settings matches device name
                    config.setValue(QZSettings::power_as_treadmill, true);
                    config.setValue(QZSettings::powerSensorName, powerSensorName);
                    configurations.push_back(config);
                    */

                    /*
                     * In order for the search to occur, the power sensor name must start with "Disabled", or
                     * power_as_bike or power_as_treadmill must be true.
                    */

                    config.setValue(QZSettings::power_sensor_as_treadmill, true);
                    config.setValue(QZSettings::power_sensor_name, "NOT " + zwiftRunPodPowerSensorName);
                    configurations.push_back(config);

                    config.setValue(QZSettings::power_sensor_as_treadmill, false);
                    config.setValue(QZSettings::power_sensor_name, "Disabled");
                    configurations.push_back(config);

                } else {
                    // disable the search
                    config.setValue(QZSettings::power_sensor_as_treadmill, false);
                    config.setValue(QZSettings::power_sensor_name, zwiftRunPodPowerSensorName);
                    config.setValue(QZSettings::power_sensor_as_bike, false);
                    configurations.push_back(config);
                }
            });


    isInitialized = true;

    // Debug log the type ids
    for(auto productTestData : testData) {
        qDebug() << "Product: " << productTestData->Name() << " expected device type id: " << productTestData->ExpectedDeviceType();
    }

   // // Validate the test data
   // for(auto productTestData : testData) {

   //     try {
   //         auto exclusions = productTestData->Exclusions();
   //     } catch(std::domain_error) {
   //         qDebug() << "Product: " << productTestData->Name() << " specifies at least 1 exclusion for which no product test data was found.";
   //     }


   // }
}


