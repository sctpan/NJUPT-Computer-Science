package top.sctpan.system.dao;

import com.mchange.v2.c3p0.ComboPooledDataSource;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;
import top.sctpan.system.domain.Course;

import java.sql.SQLException;

public class CourseDao {
    private ComboPooledDataSource dataSource;
    private QueryRunner qr;
    {
        dataSource = JdbcUtils.getDataSource();
        qr = new QueryRunner(dataSource);
    }
    public boolean addCourse(Course course){
        String sql = "insert into Course values(?,?,?,?,?)";
        Object[] params = {course.getCid(), course.getCname(), course.getCollege(), course.getGrade(), course.getTid()};
        try {
            qr.update(sql, params);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public boolean delCourse(String courseId){
        String sql = "delete from Course where Cid=?";
        Object[] params = {courseId};
        try {
            qr.update(sql, params);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public Course findCourse(String courseId){
        String sql = "select * from Course where Cid=?";
        Object[] params = {courseId};
        Course course;
        try {
            course = qr.query(sql, new BeanHandler<Course>(Course.class), params);
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
        return course;
    }

    public boolean updateCourse(Course course){
        String sql = "update Course SET Cname=?,college=?,grade=?,tid=? where Cid=?";
        Object[] params = {course.getCname(), course.getCollege(), course.getGrade(), course.getTid(),course.getCid()};
        try {
            qr.update(sql, params);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
}
