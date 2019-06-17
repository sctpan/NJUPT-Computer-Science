package top.sctpan.system.dao;

import org.apache.poi.ss.usermodel.Row;
import top.sctpan.system.domain.Course;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class ExcelUtils {
    private String path;
    private ArrayList<Course> courses;
    public ExcelUtils(){
        File f = new File("course.xlsx");
        courses = new ArrayList<Course>();
    }

    public ArrayList<Course> getCourses(){
        XSSFWorkbook workbook = null;
        try {
            InputStream is = new FileInputStream(path);
            workbook = new XSSFWorkbook(is);
        } catch (IOException e) {
            e.printStackTrace();
        }
        XSSFSheet sheet = workbook.getSheetAt(0);
        int cnt = 0;
        for (Row row : sheet) {
            if (row.getRowNum() == 0)
                continue;
            String college = row.getCell(0).getStringCellValue();
            String id = row.getCell(1).getStringCellValue();
            String name = row.getCell(2).getStringCellValue();
            String teacher = row.getCell(3).getStringCellValue();
            String grade = row.getCell(4).getStringCellValue();
            grade = grade.substring(1,3);
            HashSet<String> ids = new HashSet<String>();
            if(!ids.contains(id)){
                ids.add(id);
                cnt++;
                Course course = new Course();
                course.setCollege(college);
                course.setCid(id);
                course.setCname(name);
                course.setGrade(grade);
                DecimalFormat df=new DecimalFormat("00000");
                course.setTid(df.format(cnt));
                courses.add(course);
            }
        }
        return courses;
    }


}
