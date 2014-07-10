#include "stdafx.h"
#include <iostream> 
#include <string>
#include <stdio.h>
#include "curl/curl.h"
#include <cstddef> 
#include "diadoc_api.h"

#pragma comment(lib,"curllib.lib")

using namespace std;

static char errorBuffer[CURL_ERROR_SIZE];
static string buffer;



namespace diadoc_api_functions {
	string authorization(char *diadoc_login, char *diadoc_passwd)
	{
		CURL *curl;
		struct curl_slist *headerlist=NULL;
		struct curl_httppost *formpost=NULL;
		struct curl_httppost *lastptr=NULL;
		curl = curl_easy_init();
		//cout << diadoc_login1 << endl << endl << endl;
		char auth_url_part1[] = "https://diadoc-api.kontur.ru/Authenticate?login=";
		char auth_url_part2[sizeof(auth_url_part1) + sizeof(diadoc_login) + 12] = ""; 
		strcat(auth_url_part2, auth_url_part1);
		strcat(auth_url_part2, diadoc_login);

		//cout << diadoc_login << endl;
		//cout << endl << strlen(diadoc_login) << endl << sizeof(*diadoc_login) << endl;

		char auth_url_part3[] = "&password=";
		char auth_url_part4[sizeof(auth_url_part3) + sizeof(diadoc_passwd) + 12] = "";
		strcat(auth_url_part4, auth_url_part3);
		strcat(auth_url_part4, diadoc_passwd);

		char auth_url[sizeof(auth_url_part2) + sizeof(auth_url_part4) + 40] = "";
		strcat (auth_url, auth_url_part2);
		strcat (auth_url, auth_url_part4);

		if(curl)
			{   
				headerlist = curl_slist_append(headerlist, "POST https://diadoc-api.kontur.ru/Authenticate HTTP/1.1");
				headerlist = curl_slist_append(headerlist, "Authorization: DiadocAuth ddauth_api_client_id=comtec-e628f938-1133-449a-96d4-a105a0181e9a");
				curl_easy_setopt(curl, CURLOPT_POST, true);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
				curl_easy_setopt(curl, CURLOPT_URL, auth_url);
				string execute = execute_curl(curl, headerlist);
				return execute;
			}
		curl_easy_cleanup(curl);
	}

	string execute_curl(CURL *curl, struct curl_slist *headerlist)
	{
		string request;
		CURLcode res;
		headerlist = curl_slist_append(headerlist, "Connection: Keep-Alive");
		headerlist = curl_slist_append(headerlist, "Host: diadoc-api.kontur.ru");
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);
		//вывести подробный ответ от сервера
		curl_easy_setopt(curl, CURLOPT_VERBOSE, true);
		curl_easy_setopt(curl, CURLOPT_HEADER, true);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		res = curl_easy_perform(curl);
		if (res == CURLE_OK) {      
			int k, n;
			for (int i = 0; i < int(buffer.length()); i++) 
			{
				if (buffer[i] == '\n' && buffer[i+2] == '\n') 
				{
					k = i+3;
					n = k-1;
				}
			}
			for (k; k < int(buffer.length()); k++) 
			{
				request += buffer[k];
			}
		}
		else  
		{
			request = errorBuffer; 
		}
		return request;
	}
	
	static int writer(char *data, size_t size, size_t nmemb, string *buffer)
	{
	  //переменная - результат, по умолчанию нулевая
	  int result = 0;
	  //проверяем буфер
	  if (buffer != NULL)
	  {
		//добавляем к буферу строки из data, в количестве nmemb
		buffer->append(data, size * nmemb);
		//вычисляем объем принятых данных
		result = size * nmemb;
	  }
	  //вовзращаем результат
	  return result;
	}

}