/*
	main.cpp
	�A�b�v�f�[�g�pexe�̃\�[�X�R�[�h�ł��B
*/

#include <iostream>

#define ZIP_URL "http://runachama.com/WalletCheck/files/newest/Release.zip"
#define ZIP_NAME "Release.zip"
#define WALLETCHECK_CFG "WalletCheck.exe.config"

using namespace std;
using namespace System;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections::Generic;
using namespace System::Configuration;
using namespace System::IO::Compression;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System::Net;

// �ݒ�t�@�C���̃L�[�ƒl��ۑ�����N���X
ref class Key
{
	public:
		String^ keyname;
		String^ value;
		Key(String^ k,String^ v)
		{
			keyname = k;
			value = v;
		}
};

// �A�b�v�f�[�g���_�E�����[�h����
int download()
{
	WebClient^ wc = gcnew WebClient();
	try
	{
		wc->DownloadFile(ZIP_URL, ZIP_NAME);	//�t�@�C���̃_�E�����[�h
	}
	catch(Exception^ e)
	{
		return -1;	//���s������-1��Ԃ�
	}

	return 0;
}

// �ꎞ�t�@�C�����폜����
void clear_tmp()
{
	DirectoryInfo^ di = gcnew DirectoryInfo("./tmp");	//tmp�t�H���_�̏��
	if (di->Exists == true)	//tmp�����݂�����
	{
		for each (String ^ path in Directory::GetFiles("./tmp", "*"))	//tmp���̃t�@�C���ꗗ���擾
		{
			File::Delete(path);	//�t�@�C�����폜
		}
	}
}

// config���o�b�N�A�b�v����
void backup_config(List<Key^>% backup)
{
	//�J��config�t�@�C�����w�肷��
	ExeConfigurationFileMap^ cfg_filemap = gcnew ExeConfigurationFileMap();
	cfg_filemap->ExeConfigFilename = WALLETCHECK_CFG;
	auto config = ConfigurationManager::OpenMappedExeConfiguration(cfg_filemap, ConfigurationUserLevel::None);
	
	//config�ɂ���L�[�����ׂĕϐ��ɕۑ�����
	for each (String ^ keyname in config->AppSettings->Settings->AllKeys)
	{
		String^ value = config->AppSettings->Settings[keyname]->Value;
		Key^ key = gcnew Key(keyname,value);
		backup.Add(key);
	}
}

// config��V�����t�@�C���Ɉ����p��
void restor_config(List<Key^>% backup)
{
	//�J��config�t�@�C�����w�肷��
	ExeConfigurationFileMap^ cfg_filemap = gcnew ExeConfigurationFileMap();
	cfg_filemap->ExeConfigFilename = WALLETCHECK_CFG;
	auto config = ConfigurationManager::OpenMappedExeConfiguration(cfg_filemap, ConfigurationUserLevel::None);
	
	// �ϐ�����config�̃L�[��ǂ݂����ăt�@�C���ɕۑ�����
	for each (Key^ key in backup)
	{
		config->AppSettings->Settings[key->keyname]->Value = key->value;
	}
	config->Save();
}

int main(void)
{
	cout << "WalletCheck���A�b�v�f�[�g���܂��B" << endl;
	cout << "�t�@�C�����_�E�����[�h��" << endl;
	if (download() == 0)	//�_�E�����[�h������������
	{
		cout << "�_�E�����[�h����" << endl;
		cout << "Zip�t�@�C����W�J���Ă��܂��B" << endl;

		clear_tmp();	//tmp�����

		ZipFile::ExtractToDirectory(ZIP_NAME, "./tmp");	//zip�W�J
		cout << "�W�J����" << endl;

		File::Delete(ZIP_NAME);	//����zip�͎g��Ȃ��̂ŏ���

		cout << "Config���o�b�N�A�b�v���Ă��܂��B" << endl;
		List<Key^> backup;
		backup_config(backup); //backup�Ɋ�����Config��ۑ�
		cout << "Config�̃o�b�N�A�b�v����" << endl;
		cout << "�t�@�C�����R�s�[���Ă��܂��B" << endl;

		// tmp����t�@�C�����R�s�[���ď㏑��
		for each (String ^ newfile_path in Directory::GetFiles("./tmp", "*"))
		{
			String^ filename = Path::GetFileName(newfile_path);
			try
			{
				File::Copy(newfile_path, filename, true);
			}
			catch (Exception^ e)	//�t�@�C�����J����Ă��ď㏑���ł��Ȃ��Ƃ��Ȃ�
			{
				Console::WriteLine(e->ToString() + filename + "���X�L�b�v���܂�");
			}
		}

		cout << "Config�̕������Ă��܂��B" << endl;
		restor_config(backup);	//config���t�@�C���ɏ�������
		cout << "Config��������" << endl;

		cout << "�A�b�v�f�[�g���������܂����B" << endl;
		clear_tmp();	//�ꎞ�t�@�C���폜
	}
	else
	{
		cout << "�l�b�g���[�N�G���[�F�ڑ����m�F���Ă��������B" << endl;
	}
	
	cout << "WalletCheck���N�����܂����H(y/n)" << endl;
	char input;
	std::cin >> input;	//���͂��󂯎��
	if (input == 'y')
	{
		Process::Start("WalletCheck.exe");	//WalletCheck�N��
	}

	return 0;
}