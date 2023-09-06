#include "app_config.h"


/// <summary>
/// Configに値を保存します。
/// </summary>
/// <param name="keyname">：Configのキー名</param>
/// <param name="value">：保存する値</param>
Void app_config::config::Set(String^ keyname,String^ value)
{
	ConfigurationManager::RefreshSection("appSettings");	//セクションをリフレッシュ
	System::Configuration::Configuration^ appconfig = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
	appconfig->AppSettings->Settings[keyname]->Value = value;	//configの指定のキーに値を登録
	appconfig->Save();
}
/// <summary>
/// Configの値を取得します。
/// </summary>
/// <param name="keyname">：Configのキー名</param>
/// <returns>取得した値</returns>
String^ app_config::config::Get(String^ keyname)
{
	ConfigurationManager::RefreshSection("appSettings");	//セクションをリフレッシュ
	String^ value = ConfigurationManager::AppSettings[keyname]->ToString();	//指定キーの値を取得
	return value;
}

/// <summary>
/// Configのキーを追加します。
/// </summary>
/// <param name="keyname">：Configのキー名</param>
/// <param name="value">：Configの値</param>

Void app_config::config::Add(String^ keyname, String^ value)
{
	System::Configuration::Configuration^ app_config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

	app_config->AppSettings->Settings->Add(keyname,value);	//指定のキーを追加
	app_config->Save();
}

/// <summary>
/// Configのキーを削除します。
/// </summary>
/// <param name="keyname">：Configのキー名</param>
Void app_config::config::Remove(String^ keyname)
{
	System::Configuration::Configuration^ app_config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

	app_config->AppSettings->Settings->Remove(keyname);	//指定のキーを削除
	app_config->Save();
}