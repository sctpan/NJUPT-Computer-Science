package com.example.sctpan.callmanager;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.sctpan.callmanager.Dao.SqliteHelper;
import com.example.sctpan.callmanager.Dao.UserDao;
import com.example.sctpan.callmanager.Entity.User;

public class LoginActivity extends AppCompatActivity {
    private EditText usernameText;
    private EditText passwordText;
    private Button loginBtn;
    private Button registerBtn;
    private Context context;
    private UserDao userDao;
    private boolean check(User user) {
        if(user == null) {
            return false;
        }else if(user.getPassword().equals(passwordText.getText().toString())) {
            return true;
        }
        return false;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        context = getApplicationContext();
        userDao = new UserDao(new SqliteHelper(context));
        registerBtn = findViewById(R.id.registerBtn);
        loginBtn = findViewById(R.id.loginBtn);
        usernameText = findViewById(R.id.usernameText);
        passwordText = findViewById(R.id.passwordText);
        registerBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(context, RegisterActivity.class);
                startActivity(i);
            }
        });

        loginBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String username = usernameText.getText().toString();
                User user = userDao.findUserByUsername(username);
                if(check(user)) {
                    Intent i = new Intent(context, MainActivity.class);
                    i.putExtra("username", username);
                    i.putExtra("uid", userDao.findUserIdByUsername(username));
                    startActivity(i);
                } else {
                    Toast toast = Toast.makeText(context, "用户名或密码错误",Toast.LENGTH_SHORT);
                    toast.show();
                    return;
                }
            }
        });

    }
}
