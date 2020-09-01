#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace std;
using namespace web::http;
using namespace web::http::client;
using namespace utility;

void RESTTest3(string_t strCompanyCode)
{
    string_t strDartAuthKey = L"8c92==========================850d13"; // ������ ���ڰ��� ����Ű
    //string_t strURL = L"http://dart.fss.or.kr/api/search.json?auth=" + strDart����Ű;
    string_t strURL = L" http://opendart.fss.or.kr/api/search.json?auth=" + strDartAuthKey;
    strURL += L"&crp_cd=" + strCompanyCode + L"&start_dt=19990101&dsp_tp=";
    uri_builder b;
    http_client client(strURL);
    auto requestTask = client.request(methods::GET);
    requestTask.wait();
    http_response response = requestTask.get();
    string_t contents = U("�������� �����ϴ�.");
    auto v1 = response.extract_json().get(); // JSON �������� ���� ����
    auto array = v1[U("list")].as_array(); // list ��ü�� �ݺ��Ǿ� �迭�� ����
    int n = array.size();
    string_t* rpt_nm = new string_t[n];
    for (int i = 0; i < n; i++)
    {
        rpt_nm[i] = array[i].at(U("rpt_nm")).as_string();
        ucout << i + 1 << U(". rpt_nam : ") << rpt_nm[i] << endl; // U(" ") �� �ؾ� �Ѵ�. U" " ���ϸ� ���ڷ� ǥ�õ�.
    }
    ucout << endl << U("Total Count : ") << n << endl;
}

int main()
{
    _setmode(_fileno(stdout), _O_WTEXT); // io.h �� fcntl.h �ʿ���.
    // ������� �ܼ�â�� ����� �� ���� �����ڵ� ���� ���ԵǾ� �־� �̸� ������ �� �ֵ��� ��带 �ٲٴ� �Լ�
    RESTTest3(L"084180");
   
    return 0;
}


