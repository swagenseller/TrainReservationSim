#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
//#include "dbHelper.h"
using namespace std;


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
 int i;
 for(i = 0; i<argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
 }
 printf("\n");
 return 0;
}

int main(int argc, char* argv[]) {
  // database portion
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  string sql;
  string test;
  string st;

  rc = sqlite3_open("Trains.db", &db);
  if( rc ) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return (0);
  } else {
    fprintf(stderr, "Opened database successfully\n");
  }

  string depart;
  int err;

  cout << "Welcome to Italian Train ticket reservation simulator. \n";
  cout << "What train station are you departing from? \n";
  cin >> depart;
  //err = departing(depart, sql, rc, zErrMsg, db, test);
  test = "SELECT STATION_NAME FROM Stations WHERE STATION_NAME = '";
  st = test + depart + "'" + ";";
  cout << st << "\n";
  rc = sqlite3_exec(db, st.c_str(), callback, 0, &zErrMsg);
  if( rc != SQLITE_OK ) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
    err = 0;
  } else {
    fprintf(stdout, "Query successfully!\n");
    err = 1;
  }


  //cout << "What train station are you arriving to? \n";
  //cin >> arrive;
}
