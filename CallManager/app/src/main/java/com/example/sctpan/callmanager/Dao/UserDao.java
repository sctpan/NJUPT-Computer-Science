package com.example.sctpan.callmanager.Dao;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;
import com.example.sctpan.callmanager.Entity.User;
public class UserDao {
    private SqliteHelper helper;
    public UserDao(SqliteHelper helper) {
        this.helper = helper;
    }
    public void addUser(User user) {
        SQLiteDatabase db = helper.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put("username", user.getUsername());
        values.put("password", user.getPassword());
        db.insert("users", null, values);
        db.close();
    }

    public User findUserByUsername(String username) {
        SQLiteDatabase db = helper.getReadableDatabase();
        String query = "select * from users where username = " + "'" + username + "'";
        Cursor cursor = db.rawQuery(query, null);
        User user = null;
        if (cursor.moveToFirst()) {
            user = new User(cursor.getString(1), cursor.getString(2));
            Log.d("UserDao", user.getUsername());
        }
        return user;
    }

    public int findUserIdByUsername(String username) {
        SQLiteDatabase db = helper.getReadableDatabase();
        String query = "select id from users where username = " + "'" + username + "'";
        Cursor cursor = db.rawQuery(query, null);
        User user = null;
        if (cursor.moveToFirst()) {
           return cursor.getInt(0);
        }
        return -1;
    }

    public void updatePassword(User user, String password) {
        SQLiteDatabase db = helper.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put("password", password);
        int i = db.update("users", values,
                "username" + " = ?",
                new String[] { String.valueOf(user.getUsername())});
        Log.d("updatePassword", "affected rows: " + i);
        db.close();
    }
}
