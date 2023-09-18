/*
	main.cpp
	アップデート用exeのソースコードです。
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

// 設定ファイルのキーと値を保存するクラス
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

// アップデートをダウンロードする
int download()
{
	WebClient^ wc = gcnew WebClient();
	try
	{
		wc->DownloadFile(ZIP_URL, ZIP_NAME);	//ファイルのダウンロード
	}
	catch(Exception^ e)
	{
		return -1;	//失敗したら-1を返す
	}

	return 0;
}

// 一時ファイルを削除する
void clear_tmp()
{
	DirectoryInfo^ di = gcnew DirectoryInfo("./tmp");	//tmpフォルダの情報
	if (di->Exists == true)	//tmpが存在したら
	{
		for each (String ^ path in Directory::GetFiles("./tmp", "*"))	//tmp内のファイル一覧を取得
		{
			File::Delete(path);	//ファイルを削除
		}
	}
}

// configをバックアップする
void backup_config(List<Key^>% backup)
{
	//開くconfigファイルを指定する
	ExeConfigurationFileMap^ cfg_filemap = gcnew ExeConfigurationFileMap();
	cfg_filemap->ExeConfigFilename = WALLETCHECK_CFG;
	auto config = ConfigurationManager::OpenMappedExeConfiguration(cfg_filemap, ConfigurationUserLevel::None);
	
	//configにあるキーをすべて変数に保存する
	for each (String ^ keyname in config->AppSettings->Settings->AllKeys)
	{
		String^ value = config->AppSettings->Settings[keyname]->Value;
		Key^ key = gcnew Key(keyname,value);
		backup.Add(key);
	}
}

// configを新しいファイルに引き継ぐ
void restor_config(List<Key^>% backup)
{
	//開くconfigファイルを指定する
	ExeConfigurationFileMap^ cfg_filemap = gcnew ExeConfigurationFileMap();
	cfg_filemap->ExeConfigFilename = WALLETCHECK_CFG;
	auto config = ConfigurationManager::OpenMappedExeConfiguration(cfg_filemap, ConfigurationUserLevel::None);
	
	// 変数からconfigのキーを読みだしてファイルに保存する
	for each (Key^ key in backup)
	{
		config->AppSettings->Settings[key->keyname]->Value = key->value;
	}
	config->Save();
}

int main(void)
{
	cout << "WalletCheckをアップデートします。" << endl;
	cout << "ファイルをダウンロード中" << endl;
	if (download() == 0)	//ダウンロードが成功したら
	{
		cout << "ダウンロード完了" << endl;
		cout << "Zipファイルを展開しています。" << endl;

		clear_tmp();	//tmpを空に

		ZipFile::ExtractToDirectory(ZIP_NAME, "./tmp");	//zip展開
		cout << "展開完了" << endl;

		File::Delete(ZIP_NAME);	//もうzipは使わないので消す

		cout << "Configをバックアップしています。" << endl;
		List<Key^> backup;
		backup_config(backup); //backupに既存のConfigを保存
		cout << "Configのバックアップ完了" << endl;
		cout << "ファイルをコピーしています。" << endl;

		// tmpからファイルをコピーして上書き
		for each (String ^ newfile_path in Directory::GetFiles("./tmp", "*"))
		{
			String^ filename = Path::GetFileName(newfile_path);
			try
			{
				File::Copy(newfile_path, filename, true);
			}
			catch (Exception^ e)	//ファイルが開かれていて上書きできないときなど
			{
				Console::WriteLine(e->ToString() + filename + "をスキップします");
			}
		}

		cout << "Configの復元しています。" << endl;
		restor_config(backup);	//configをファイルに書き込む
		cout << "Config復元完了" << endl;

		cout << "アップデートが完了しました。" << endl;
		clear_tmp();	//一時ファイル削除
	}
	else
	{
		cout << "ネットワークエラー：接続を確認してください。" << endl;
	}
	
	cout << "WalletCheckを起動しますか？(y/n)" << endl;
	char input;
	std::cin >> input;	//入力を受け取る
	if (input == 'y')
	{
		Process::Start("WalletCheck.exe");	//WalletCheck起動
	}

	return 0;
}