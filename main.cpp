#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
//#include "dbHelper.h"
using namespace std;


static int callback(void *data, int argc, char **argv, char **azColName) {
 int i;
 fprintf(stderr, "%s: ", (const char*)data);
 for(i = 0; i<argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
 }
 printf("\n");
 return 0;
}

int main(int argc, char* argv[]) {

    const char* data = "call back function called?";
  // database portion
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  string sql;
  string first;
  string sec;
  string st;
  string stat;

  rc = sqlite3_open("Trains.db", &db);
  if( rc ) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return (0);
  } else {
    fprintf(stderr, "Opened database successfully\n");
  }

  string depart;
  string arrive;
  int err = 0;

  cout << "Welcome to Italian Train ticket reservation simulator. \n";
  cout << "What train station are you departing from? \n";
  //cin >> depart;
  //err = departing(depart, sql, rc, zErrMsg, db, test);
  //first = "SELECT STATION_ID_A FROM StationSchedule WHERE STATION_ID_A = '";
  //st = first + depart + "'" + ";";
  //cout << st << "\n";
  //rc = sqlite3_exec(db, st.c_str(), callback, 0, &zErrMsg);
  while (err < 1) {
      cin >> depart;
      first = "SELECT * FROM StationSchedule WHERE STATION_ID_D = '";
      st = first + depart + "'" + ";";
      //cout << st << "\n";
      rc = sqlite3_exec(db, st.c_str(), callback, (void*)data, &zErrMsg);
      if( rc != SQLITE_OK ) {
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          fprintf(stdout, "No available connections.  Try a different selection.\n");
          sqlite3_free(zErrMsg);
      } else {
          fprintf(stdout, "Query successfully!\n");
          err = 1;
      }
  }

  cout << "What train station are you arriving to? \n";
  cin >> arrive;
  sec = "SELECT * FROM StationSchedule WHERE STATION_ID_D = '";
  //string seco = "SELECT * FROM StationSchedule WHERE STATION_ID_D = 'ROM' AND STATION_ID_A = 'MIL'";
  //stat = sec + arrive + "'" + ";";
  stat = "SELECT * FROM StationSchedule WHERE STATION_ID_D = '" + depart + "' AND STATION_ID_A = '" + arrive + "';" ;
  cout << stat << "\n";
  rc = sqlite3_exec(db, stat.c_str(), callback, 0, &zErrMsg);
  if( rc != SQLITE_OK ) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    fprintf(stdout, "No available connections.\n");
    sqlite3_free(zErrMsg);
    err = 0;
  } else {
    fprintf(stdout, "Query successfully!\n");
    err = 1;
  }

  sqlite3_close(db);
  return 0;
}
