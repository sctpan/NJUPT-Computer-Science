package com.example.sctpan.callmanager.Dao;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.example.sctpan.callmanager.Entity.PhoneCall;
import com.example.sctpan.callmanager.Entity.User;

import java.util.ArrayList;

public class PhoneCallDao {
    private SqliteHelper helper;
    public PhoneCallDao(SqliteHelper helper) {
        this.helper = helper;
    }
    public boolean addPhoneCall(PhoneCall phoneCall) {
        if(!existPhoneCall(phoneCall.getNumber(), phoneCall.getDate())) {
            SQLiteDatabase db = helper.getWritableDatabase();
            ContentValues values = new ContentValues();
            values.put("number", phoneCall.getNumber());
            values.put("date", phoneCall.getDate());
            values.put("uid", phoneCall.getUid());
            db.insert("phonecalls", null, values);
            db.close();
            Log.d("addPhoneCall", phoneCall.getUid() + "");
            return true;
        }
        Log.d("addPhoneCall", "duplicate");
        return false;
    }

    public ArrayList<PhoneCall> getAllPhoneCalls(int uid) {
        SQLiteDatabase db = helper.getReadableDatabase();
        ArrayList<PhoneCall> phoneCalls = new ArrayList<>();
        String query = "select * from phonecalls where uid = " + "'" + uid + "'";
        Cursor cursor = db.rawQuery(query, null);
        PhoneCall phoneCall = null;
        if (cursor.moveToFirst()) {
            do {
                phoneCall = new PhoneCall(cursor.getString(1),cursor.getLong(2),cursor.getInt(3));
                phoneCalls.add(phoneCall);
            } while (cursor.moveToNext());
        }
        return phoneCalls;
    }

    public boolean existPhoneCall(String number, Long date) {
        SQLiteDatabase db = helper.getReadableDatabase();
        Long before = date - 50;
        String query = "select * from phonecalls where number = " + "'" + number + "'" + "and date > " +
                "'" + before + "'";
        Cursor cursor = db.rawQuery(query, null);
        if (cursor.moveToFirst()) {
            return true;
        }
        return false;
    }

}
