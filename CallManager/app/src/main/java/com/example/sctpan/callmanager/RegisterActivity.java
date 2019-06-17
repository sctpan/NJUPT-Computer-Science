package com.example.sctpan.callmanager;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.sctpan.callmanager.Dao.SqliteHelper;
import com.example.sctpan.callmanager.Dao.UserDao;
import com.example.sctpan.callmanager.Entity.User;

public class RegisterActivity extends AppCompatActivity {
    private Button registerBtn;
    private EditText usernameText;
    private EditText passwordText;
    private EditText confirmPasswordText;
    private Context context;
    private UserDao userDao;
    public void clearAll() {
        usernameText.setText("");
        passwordText.setText("");
        confirmPasswordText.setText("");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);
        context = getApplicationContext();
        userDao = new UserDao(new SqliteHelper(context));
        registerBtn = findViewById(R.id.registerBtn);
        registerBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                usernameText = findViewById(R.id.usernameText);
                passwordText = findViewById(R.id.passwordText);
                confirmPasswordText = findViewById(R.id.confirmPasswordText);
                String username = usernameText.getText().toString();
                String password = passwordText.getText().toString();
                String confirmPassword = confirmPasswordText.getText().toString();
                Log.d("password", password);
                Log.d("confirm", confirmPassword);
                if(username.equals("") || password.equals("")) {
                    Toast toast = Toast.makeText(context, "请填写用户名或密码！",Toast.LENGTH_SHORT);
                    toast.show();
                    return;
                }
                if(userDao.findUserByUsername(username) != null) {
                    Log.d("Register", "duplicate!");
                    Toast toast = Toast.makeText(context, "用户名已存在！",Toast.LENGTH_SHORT);
                    toast.show();
                    clearAll();
                    return;
                }

                if(password.equals(confirmPassword)) {
                    Log.d("Login", "start to connecting to database");
                    userDao.addUser(new User(username, password));
                    Log.d("Login", "add success");
                    Toast toast = Toast.makeText(context, "注册成功",Toast.LENGTH_SHORT);
                    toast.show();
                    Intent i = new Intent(context, LoginActivity.class);
                    startActivity(i);
                } else {
                    Toast toast = Toast.makeText(context, "两次密码输入不一致！",Toast.LENGTH_SHORT);
                    toast.show();
                    passwordText.setText("");
                    confirmPasswordText.setText("");
                    return;
                }
            }
        });

    }
}
