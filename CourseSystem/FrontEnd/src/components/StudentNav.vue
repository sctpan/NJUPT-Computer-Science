<template>
  <div>
    <Row id="header">
      <Col span="6"><span>南邮选课管理系统</span></Col>
      <Col span="12" offset="6">
        <Menu mode="horizontal" active-name="1" @on-select="selected">
          <Submenu name="1">
            <template slot="title">
              <Icon type="ios-stats" />
              课程选修
            </template>
            <MenuItem name="1-1" to="/student/optionalCourse">可选课程</MenuItem>
            <MenuItem name="1-2" to="/student/selectedCourse">已选课程</MenuItem>
          </Submenu>
          <MenuItem name="2" to="/student/studentScore">
            <Icon type="ios-paper" />
            成绩查询
          </MenuItem>
          <Submenu name="3">
            <template slot="title">
              <Icon type="ios-stats" />
              账号设置
            </template>
            <MenuItem name="3-1">个人信息</MenuItem>
            <MenuItem name="3-2" to="/student/password">密码修改</MenuItem>
          </Submenu>
        </Menu>
      </Col>
    </Row>
    <Modal v-model="modal1" title="个人信息" cancel-text="">
      <div id="content">
        <p>
          <label>学号</label>
          <span>{{ id }}</span>
        </p>
        <p>
          <label>姓名</label>
          <span>{{ name }}</span>
        </p>
        <p>
          <label>班级</label>
          <span>{{ classId }}</span>
        </p>
        <p>
          <label>学院</label>
          <span>{{ college }}</span>
        </p>
        <p>
          <label>性别</label>
          <span>{{ sex }}</span>
        </p>
        <p>
          <label>年龄</label>
          <span>{{ age }}</span>
        </p>
      </div>

    </Modal>
  </div>
</template>

<script>
    export default {
        name: "StudentNav",
        data(){
          return {
            modal1: false,
            id:"",
            name:"",
            classId:"",
            college:"",
            sex:"",
            age:""
          }
        },
        created(){
          this.getStudent();
        },
        methods:{
          selected(name){
            if(name == "3-1"){
              this.modal1 = true;
            }
          },
          getStudent(){
            this.$http.get("student", {params:{method:"findStudent",id:"B15010102"}}).then(response => {
              var result = response.body;
              if(result.status == "success"){
                this.name = result.data.name;
                this.id = result.data.id;
                this.classId = result.data.classId;
                this.college = result.data.college;
                this.age = result.data.age;
                if(result.data.sex === "male"){
                  this.sex = "男";
                }else{
                  this.sex = "女";
                }
              }else{
                this.$Message.error(result.error);
              }
            }, response => {
              this.$Message.error("发生错误");
            });
          }
        }
    }
</script>

<style scoped>
  #header{
    height: 60px;
    line-height: 60px;
    font-size: 20px;
  }
  #content{
    font-size: 16px;
  }
  #content span{
    margin-left: 12px;
  }

</style>
