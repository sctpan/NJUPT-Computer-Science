package top.sctpan.system.dao;

import com.mchange.v2.c3p0.ComboPooledDataSource;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;
import top.sctpan.system.domain.Student;

import java.sql.SQLException;

public class StudentDao {
    private ComboPooledDataSource dataSource;
    private QueryRunner qr;
    {
        dataSource = JdbcUtils.getDataSource();
        qr = new QueryRunner(dataSource);
    }

    public boolean addStudent(Student stu){
        String sql = "insert into Student values(?,?,?,?,?,?,?)";
        Object[] params = {stu.getSid(), stu.getSname(), stu.getSclass(), stu.getCollege(), stu.getAge(), stu.getSex(),stu.getPassword()};
        try {
            qr.update(sql, params);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public boolean delStudent(String stuId){
        String sql = "delete from Student where sid=?";
        Object[] params = {stuId};
        try {
            qr.update(sql, params);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public Student findStudent(String stuId){
        String sql = "select * from Student where sid=?";
        Object[] params = {stuId};
        Student stu;
        try {
            stu = qr.query(sql, new BeanHandler<Student>(Student.class), params);
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
        return stu;
    }

    public boolean updateStudent(Student stu){
        String sql = "update Student SET sname=?,sclass=?,college=?,age=?,sex=? where sid=?";
        Object[] params = {stu.getSname(), stu.getSclass(), stu.getCollege(), stu.getAge(), stu.getSex(),stu.getSid()};
        try {
            qr.update(sql, params);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
}
