package com.example.sctpan.callmanager;

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

public class PasswordActivity extends AppCompatActivity {
    private EditText oldPasswordText;
    private EditText newPasswordText;
    private EditText confirmPasswordText;
    private Button editPwdBtn;
    private Context context;
    private UserDao userDao;
    private User user;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_password);
        oldPasswordText = findViewById(R.id.oldPasswordText);
        newPasswordText = findViewById(R.id.newPasswordText);
        confirmPasswordText = findViewById(R.id.confirmPasswordText);
        editPwdBtn = findViewById(R.id.editPwdBtn);
        context = getApplicationContext();
        userDao = new UserDao(new SqliteHelper(context));
        Intent i = getIntent();
        user = userDao.findUserByUsername(i.getStringExtra("username"));
        editPwdBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String oldPassword = oldPasswordText.getText().toString();
                String newPassword = newPasswordText.getText().toString();
                String confirmPassword = confirmPasswordText.getText().toString();
                if(check(oldPassword, newPassword, confirmPassword)) {
                    userDao.updatePassword(user, confirmPassword);
                    Toast toast = Toast.makeText(context, "密码修改成功", Toast.LENGTH_SHORT);
                    toast.show();
                    Intent intent = new Intent(context, LoginActivity.class);
                    startActivity(intent);
                }
            }
        });
    }

    private boolean check(String oldPassword, String newPassword, String confirmPassword) {
        if(oldPassword.equals("") || newPassword.equals("") || confirmPassword.equals("")) {
            Toast toast = Toast.makeText(this.context, "字段不得为空", Toast.LENGTH_SHORT);
            toast.show();
            return false;
        }
        if(!oldPassword.equals(user.getPassword())) {
            Toast toast = Toast.makeText(this.context, "原密码不正确", Toast.LENGTH_SHORT);
            toast.show();
            return false;
        }
        if(!newPassword.equals(confirmPassword)) {
            Toast toast = Toast.makeText(this.context, "密码不一致", Toast.LENGTH_SHORT);
            toast.show();
            return false;
        }
        return true;
    }
}
