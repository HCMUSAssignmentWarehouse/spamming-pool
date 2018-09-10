const mysql = require('mysql'),
    q = require('q');

const _HOST = '127.0.0.1',
    _USER = 'root',
    _PWD = '12345678',
    _DB = 'bankmanagement'; //TODO: Change this

exports.load = (sql) => {
    let d = q.defer();

    let cn = mysql.createConnection({
        host: _HOST,
        user: _USER,
        password: _PWD,
        database: _DB
    });
    cn.connect();
    cn.query(sql, (err, rows, fields) => {
        if (err) {
            d.reject(err);
        } else {
            d.resolve(rows);
        }
        cn.end();
    });

    return d.promise;
};

exports.insert = sql => {
    let d = q.defer();

    let cn = mysql.createConnection({
        host: _HOST,
        user: _USER,
        password: _PWD,
        database: _DB
    });
    cn.connect();
    cn.query(sql, (err, value) => {
        if (err) {
            d.reject(err);
        } else {
            d.resolve(value.insertId);
        }
        cn.end();
    });

    return d.promise;
};