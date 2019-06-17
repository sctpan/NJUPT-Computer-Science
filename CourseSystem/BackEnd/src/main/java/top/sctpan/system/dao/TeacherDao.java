package top.sctpan.system.dao;

import com.mchange.v2.c3p0.ComboPooledDataSource;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;
import top.sctpan.system.domain.Teacher;
import top.sctpan.system.domain.Teacher;

import java.sql.SQLException;

public class TeacherDao {
    private ComboPooledDataSource dataSource;
    private QueryRunner qr;
    {
        dataSource = JdbcUtils.getDataSource();
        qr = new QueryRunner(dataSource);
    }

    public boolean addTeacher(Teacher tch){
        String sql = "insert into Teacher values(?,?,?)";
        Object[] params = {tch.getTid(), tch.getTname(), tch.getPassword()};
        try {
            qr.update(sql, params);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public boolean delTeacher(String tchId){
        String sql = "delete from Teacher where tid=?";
        Object[] params = {tchId};
        try {
            qr.update(sql, params);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public Teacher findTeacher(String tchId){
        String sql = "select * from Teacher where tid=?";
        Object[] params = {tchId};
        Teacher tch;
        try {
            tch = qr.query(sql, new BeanHandler<Teacher>(Teacher.class), params);
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
        return tch;
    }

    public boolean updateTeacher(Teacher tch){
        String sql = "update Teacher SET tname=? where tid=?";
        Object[] params = {tch.getTname()};
        try {
            qr.update(sql, params);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
}
