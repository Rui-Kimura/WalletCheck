#include "app_config.h"


/// <summary>
/// Config�ɒl��ۑ����܂��B
/// </summary>
/// <param name="keyname">�FConfig�̃L�[��</param>
/// <param name="value">�F�ۑ�����l</param>
Void app_config::config::Set(String^ keyname,String^ value)
{
	ConfigurationManager::RefreshSection("appSettings");	//�Z�N�V���������t���b�V��
	System::Configuration::Configuration^ appconfig = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
	appconfig->AppSettings->Settings[keyname]->Value = value;	//config�̎w��̃L�[�ɒl��o�^
	appconfig->Save();
}
/// <summary>
/// Config�̒l���擾���܂��B
/// </summary>
/// <param name="keyname">�FConfig�̃L�[��</param>
/// <returns>�擾�����l</returns>
String^ app_config::config::Get(String^ keyname)
{
	ConfigurationManager::RefreshSection("appSettings");	//�Z�N�V���������t���b�V��
	String^ value = ConfigurationManager::AppSettings[keyname]->ToString();	//�w��L�[�̒l���擾
	return value;
}

/// <summary>
/// Config�̃L�[��ǉ����܂��B
/// </summary>
/// <param name="keyname">�FConfig�̃L�[��</param>
/// <param name="value">�FConfig�̒l</param>

Void app_config::config::Add(String^ keyname, String^ value)
{
	System::Configuration::Configuration^ app_config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

	app_config->AppSettings->Settings->Add(keyname,value);	//�w��̃L�[��ǉ�
	app_config->Save();
}

/// <summary>
/// Config�̃L�[���폜���܂��B
/// </summary>
/// <param name="keyname">�FConfig�̃L�[��</param>
Void app_config::config::Remove(String^ keyname)
{
	System::Configuration::Configuration^ app_config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

	app_config->AppSettings->Settings->Remove(keyname);	//�w��̃L�[���폜
	app_config->Save();
}