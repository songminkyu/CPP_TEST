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
//
//USES_CONVERSION;
//std::string s1;
//std::wstring s2(A2W(s1.c_str())); // wstring <- string
//for (int i = 0; i < n; i++)
//{
//    rpt_nm[i] = array[i].at(U("rpt_nm")).as_string();
//    strStr = W2A(rpt_nm[i].c_str()); // string <- wstring 
//    cout << i + 1 << ". rpt_nam : " << strStr << endl;
//}
//cout << endl << "Total Count : " << n << endl;
//CString str = rpt_nm[0].c_str();
//AfxMessageBox(str);
//



void RESTTest4(string_t strCompanyCode)
{
    string_t strDartAuth = L"8c92...70...";
    string_t strURL = L"http://dart.fss.or.kr/api/search.json?auth=" + strDartAuth;
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
    CString str = rpt_nm[0].c_str();
    AfxMessageBox(str);
}

int main()
{
    _setmode(_fileno(stdout), _O_WTEXT); // io.h �� fcntl.h �ʿ���.
    // ������� �ܼ�â�� ����� �� ���� �����ڵ� ���� ���ԵǾ� �־� �̸� ������ �� �ֵ��� ��带 �ٲٴ� �Լ�
    RESTTest4(L"084180");
    _gettchar();
    return 0;
}


