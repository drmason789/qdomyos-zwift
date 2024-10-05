#ifndef DEVICEDISCOVERYINFO_H
#define DEVICEDISCOVERYINFO_H

#include <QSettings>
#include <QString>
#include <QMap>

/**
 * @brief Settings used during the device discovery process.
 */
class DeviceDiscoveryInfo {
    QMap<QString, QVariant> values;
public :
    /**
     * @brief Constructor.
     * @param loadDefaults Indicates if the default values should be loaded.
     */
    explicit DeviceDiscoveryInfo(bool loadDefaults=true);

    /**
     * @brief Configures the QSettings object.
     * @param settings
     * @param clear Specifies whether to clear the settings object.
     */
    void setValues(QSettings& settings, bool clear=true) const;

    /**
     * @brief Loads this object with values from the QSettings object.
     */
    void getValues(QSettings& settings);

    /**
     * @brief Temporarily creates an empty QSettings object and loads this object's members from it.
     */
    void loadDefaultValues();

    /**
     * @brief Gets the value for the specified key, or the default value if the key is not present.
     * @param key
     * @param defaultValue
     * @return
     */
    QVariant Value(const QString& key, const QVariant& defaultValue) const;


    /**
     * @brief Gets the value for the specified key.
     * @param key
     * @return
     */
    QVariant Value(const QString& key) const;

    /**
     * @brief Sets the value for the specified key.
     * @param key
     * @param value
     */
    void setValue(const QString& key, const QVariant& value);

};

#endif // DEVICEDISCOVERYINFO_H
