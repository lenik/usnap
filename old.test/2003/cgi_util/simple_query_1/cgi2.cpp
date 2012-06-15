// cgi2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

    char QueryString[1000];

    bool bFound = false;
    cout    << "Content-Type: text/html" << endl
            << endl
            ;

    cout    << "<html><body>Return: <HR>" << endl;

    char *pEnv;
    int envi = 0;
    while (pEnv = _environ[envi]) {
        char *spart = strchr(pEnv, '=');
        if (spart) {
            *spart = 0;
            if (!strcmpi(pEnv, "QUERY_STRING")) {
                strcpy(QueryString, spart + 1);
                bFound = true;
                break;
            }
            *spart = '=';

            //cout    << "<PLAIN>" << pEnv << "</PLAIN><BR>";
        }

        //cout    << "<PLAIN>[" << envi << "]" << _environ[envi] << "</PLAIN><BR>";

        envi++;
    }

    if (!bFound) {
        cout    << "<P> You haven't input name & age. </P>"
            ;
    } else {
        char *sName = 0;
        char *sAge = 0;

        char *tok = strtok(QueryString, "&");
        while (tok) {
            char *sValue = strchr(tok, '=');
            *sValue++ = 0;

            if (!strcmpi(tok, "Name")) sName = sValue;
            if (!strcmpi(tok, "Age")) sAge = sValue;

            tok = strtok(NULL, "&");
        }

        cout    << "<P> Your name is " << sName << ".</P>" << endl;
        cout    << "<P> You are " << sAge << " years old. </P>" << endl;

    }

    cout    << "</body></html>" << endl;

	return 0;
}
