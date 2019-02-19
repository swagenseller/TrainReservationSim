// import sqlite3 module
const sqlite3 = require('sqlite3').verbose();

function getTrains() {
    var dropdown = [];
    // check attempts to connect to database
    let db = new sqlite3.Database('databaseFiles/Trains.db', (err) => {
        if (err) {
            return console.log(err.message);
        }
        console.log('Connected to Trains.db local SQlite database.');
    });

    // fills dropdown array with train stations
    let stations = 'SELECT STATION_NAME name FROM Stations';

    db.all(stations, [], (err,rows) => {
        if (err) {
            throw err;
        }
        rows.forEach((row) => {
            dropdown.push(row.name);
            console.log(row.name);
        });
    });

    // close the database connection
    db.close((err) => {
      if (err) {
        return console.error(err.message);
      }
      console.log('Close the database connection.');
    });

    return dropdown;
}
