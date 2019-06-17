package com.example.sctpan.callmanager;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import com.example.sctpan.callmanager.Dao.PhoneCallDao;
import com.example.sctpan.callmanager.Dao.SqliteHelper;
import com.example.sctpan.callmanager.Entity.PhoneCall;
import java.util.Date;

public class MainActivity extends AppCompatActivity {
    private TextView userText;
    private Button queryBtn;
    private Button editPwdBtn;
    private Button logoutBtn;
    private static TelephonyManager tm;
    private static final String TAG="MAIN";
    private Context context;
    private PhoneCallDao phoneCallDao;
    private int uid;
    private String username;
    private PhoneStateListener mPhoneStateListener;
    private Intent intent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        context = getApplicationContext();
        userText = findViewById(R.id.userText);
        queryBtn = findViewById(R.id.queryBtn);
        editPwdBtn = findViewById(R.id.editPwdBtn);
        logoutBtn = findViewById(R.id.logoutBtn);
        phoneCallDao = new PhoneCallDao(new SqliteHelper(context));
        intent = getIntent();
        username = intent.getStringExtra("username");
        uid = intent.getIntExtra("uid",-1);
        tm = (TelephonyManager) getSystemService(TELEPHONY_SERVICE);
        userText.setText("Welcome, " + username);
        mPhoneStateListener = new PhoneStateListener() {
            public void onCallStateChanged(int state, String incomingNumber) {
                super.onCallStateChanged(state, incomingNumber);
                if(state == TelephonyManager.CALL_STATE_RINGING) {
                    Date date = new Date();
                    Log.d("MainActivity","username: " + username + ", uid: " + uid);
                    if(phoneCallDao.addPhoneCall(new PhoneCall(incomingNumber, date.getTime(), uid))){
                        Toast toast = Toast.makeText(context, "有来电信息，已保存",Toast.LENGTH_SHORT);
                        toast.show();
                    }
                }
            }
        };
        tm.listen(mPhoneStateListener, PhoneStateListener.LISTEN_CALL_STATE);
        queryBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(context, QueryActivity.class);
                i.putExtra("uid", uid);
                startActivity(i);
            }
        });
        editPwdBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(context, PasswordActivity.class);
                i.putExtra("username", username);
                startActivity(i);
            }
        });

        logoutBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                tm.listen(mPhoneStateListener,PhoneStateListener.LISTEN_NONE);
                Intent i = new Intent(context, LoginActivity.class);
                startActivity(i);
            }
        });
    }
}
