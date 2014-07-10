// diadoc_example.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <stdio.h>
#include "curl/curl.h"
#include <cstddef> 
#include "diadoc_api.h"
#pragma comment(lib,"curllib.lib")
//---------------------------------------------------------------------------

using namespace std;
const char * file = "D:\\Documents and Settings\\kuzmin\\ћои документы\\Visual Studio 2010\\Projects\\test\\Debug\\tmp.xml";

//string send_message(char * token);
//string get_organisation(char * token);


int _tmain(int argc, _TCHAR* argv[])
{
	//==========авторизаци€ с получением токена и преобразование токена в массив char
	char diadoc_login[] = "kuzmin@comtec.ru";
	char diadoc_passwd[] = "Comtec1";

	string token = diadoc_api_functions::authorization(diadoc_login, diadoc_passwd);
	const char * c_token = token.c_str();
	char n_token[139];
	strcpy(n_token, c_token); 
	cout << n_token << endl << endl;






	//===============================================================================




	//string uuu = get_organisation(n_token);
	//cout << uuu << endl;
	
			//	string uuu = send_message(n_token);
			//	cout << uuu << endl;

	//================запись в файл===================================================
	/*ofstream fout(file, ios::out | ios::app);
	if (!fout.is_open())
	{
		cout << "error" << endl;
		exit(EXIT_FAILURE);
	}
	fout << uuu <<  endl;
	fout.close();*/
	//=================================================================================
    getchar();
	return 0;
}

/*

string send_message(char * token)
{
	CURL *curl;
	struct curl_slist *headerlist=NULL;
	struct curl_httppost *formpost=NULL;
	struct curl_httppost *lastptr=NULL;
    curl = curl_easy_init();
    if(curl)
        { 
			char head[] = "Authorization: DiadocAuth ddauth_api_client_id=comtec-e628f938-1133-449a-96d4-a105a0181e9a, ddauth_token=";
			char auth_token[246];
			strcpy(auth_token, head);
			strcat(auth_token, token);
			headerlist = curl_slist_append(headerlist, "POST https://diadoc-api.kontur.ru/Authenticate HTTP/1.1");
			headerlist = curl_slist_append(headerlist, auth_token);
			curl_easy_setopt(curl, CURLOPT_POST, true);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "FromBoxId=d7fe98d55f0d4fc196400a97f058a055@diadoc.ru");
			curl_easy_setopt(curl, CURLOPT_URL, "https://diadoc-api.kontur.ru//V3/PostMessage");
			string ttt = execute_curl(curl, headerlist);
			return ttt;
        }
	curl_easy_cleanup(curl);
}

string get_organisation(char * token)
{
	CURL *curl;
	struct curl_slist *headerlist=NULL;
	struct curl_httppost *formpost=NULL;
	struct curl_httppost *lastptr=NULL;
    curl = curl_easy_init();
    if(curl)
        { 
			char head[] = "Authorization: DiadocAuth ddauth_api_client_id=comtec-e628f938-1133-449a-96d4-a105a0181e9a, ddauth_token=";
			char auth_token[246];
			strcpy(auth_token, head);
			strcat(auth_token, token);
			headerlist = curl_slist_append(headerlist, "POST https://diadoc-api.kontur.ru/Authenticate HTTP/1.1");
			headerlist = curl_slist_append(headerlist, auth_token);
			curl_easy_setopt(curl, CURLOPT_URL, "https://diadoc-api.kontur.ru/GetOrganization?inn=7733012017&outputFormat=xml");
			//curl_easy_setopt(curl, CURLOPT_URL, "https://diadoc-api.kontur.ru//GetCounteragents?myOrgId=7264b16c-6ed4-4c79-9079-c8c3e791d6e9");
			string ttt = execute_curl(curl, headerlist);
			return ttt;
        }
	curl_easy_cleanup(curl);
}



*/