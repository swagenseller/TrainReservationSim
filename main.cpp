#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <vector>
#include "Train.h"
using namespace std;

vector<char*> queryVector;

static int callback(void *data, int argc, char **argv, char **azColName) {
 int i;
 //queryVector.clear();
 fprintf(stderr, "%s:\n", (const char*)data);
 //Train test;
 for(i = 0; i<argc; i++) {
    //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    printf("%s\n", argv[i] ? argv[i] : "NULL");
    queryVector.push_back(argv[i]);
 }
 printf("\n");
 return 0;
}

int main(int argc, char* argv[]) {

    const char* data = "call back function called";
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
  cin >> depart;
  /*while (err < 1) {
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
*/
  cout << "What train station are you arriving to? \n";
  cin >> arrive;
  //cout << "What time do you want to arrive in " + arrive + "\n";
  //cin >> eta;
  //stat = "SELECT * FROM StationSchedule WHERE STATION_ID_D = '" + depart + "' AND STATION_ID_A = '" + arrive + "';" ;
  string query = "SELECT s1.STATION_NAME, s2.STATION_NAME, ss.DEPARTURE_TIME, ss.ARRIVAL_TIME "\
                 "FROM Stations s1, Stations s2, StationSchedule ss "\
                 "WHERE ss.STATION_ID_D = '" + depart +"' AND ss.STATION_ID_A = '" + arrive +"' AND s1.ID = ss.STATION_ID_D AND s2.ID = ss.STATION_ID_A;";
  cout << stat << "\n";
  rc = sqlite3_exec(db, query.c_str(), callback, 0, &zErrMsg);
  if( rc != SQLITE_OK ) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    fprintf(stdout, "No available connections.\n");
    sqlite3_free(zErrMsg);
    err = 0;
  } else {
    fprintf(stdout, "Query successfully!\n");
    err = 1;
  }
  cout << "Iterating the queryVector \n";
  cout << queryVector.size();
  cout << "\n";
  for (int i = 0; i < queryVector.size(); i++) {
      cout << queryVector[i];
      cout << "\n";
  }
  queryVector.clear();
  sqlite3_close(db);
  return 0;
}
