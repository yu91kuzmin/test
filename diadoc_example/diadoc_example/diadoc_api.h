#ifndef diadoc__api_h
#define diadoc__api_h

using namespace std;
 
namespace diadoc_api_functions {
	//авторизация, функция принимает логин/пароль
	string authorization(char *diadoc_login, char *diadoc_passwd);
	string execute_curl(CURL *curl, struct curl_slist *headerlist);
	static int writer(char *data, size_t size, size_t nmemb, string *buffer);






}
#endif