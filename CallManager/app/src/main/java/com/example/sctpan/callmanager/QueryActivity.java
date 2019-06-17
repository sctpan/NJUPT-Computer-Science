package com.example.sctpan.callmanager;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;

import com.example.sctpan.callmanager.Dao.PhoneCallDao;
import com.example.sctpan.callmanager.Dao.SqliteHelper;
import com.example.sctpan.callmanager.Entity.PhoneCall;

public class QueryActivity extends AppCompatActivity {
    private Context context;
    private PhoneCallDao phoneCallDao;
    private int uid;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_query);
        context = getApplicationContext();
        phoneCallDao = new PhoneCallDao(new SqliteHelper(context));
        Intent i = getIntent();
        uid = i.getIntExtra("uid", -1);
        MyAdapter adapter = new MyAdapter(this, phoneCallDao.getAllPhoneCalls(uid));
        ListView listView = (ListView) findViewById(R.id.itemList);
        listView.setAdapter(adapter);
    }
}
