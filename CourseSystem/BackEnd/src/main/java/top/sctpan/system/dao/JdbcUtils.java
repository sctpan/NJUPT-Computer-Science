package top.sctpan.system.dao;
import com.mchange.v2.c3p0.ComboPooledDataSource;
public class JdbcUtils {
    private static ComboPooledDataSource dataSource;
    static{
        dataSource = new ComboPooledDataSource();
    }
    public static ComboPooledDataSource getDataSource(){
        return dataSource;
    }
}
