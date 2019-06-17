package com.example.sctpan.callmanager.Dao;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class SqliteHelper extends SQLiteOpenHelper{
        private static final int DATABASE_VERSION = 1;
        private static final String DATABASE_NAME = "CallManagerDB";
        public SqliteHelper(Context context) {
            super(context, DATABASE_NAME, null, DATABASE_VERSION);
        }
        @Override
        public void onCreate(SQLiteDatabase db) {
            String CREATE_USER_TABLE = "CREATE TABLE users ( " +
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                    "username TEXT, "+
                    "password TEXT )";
            String CREATE_PHONECALL_TABLE = "CREATE TABLE phonecalls ( " +
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                    "number TEXT, "+
                    "date INTEGER, " +
                    "uid INTEGER, " +
                    "FOREIGN KEY(uid) REFERENCES users(id))";
            db.execSQL(CREATE_USER_TABLE);
            db.execSQL(CREATE_PHONECALL_TABLE);
        }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        this.onCreate(sqLiteDatabase);
    }
}
