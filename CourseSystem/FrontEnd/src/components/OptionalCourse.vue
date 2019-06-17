<template>
  <div>
    <Table border ref="selection" :columns="columns" :data="courses" @on-selection-change='selectionClick'></Table>
    <Button type="primary" @click="selectCourse">提交选课</Button>
  </div>
</template>
<script>
  export default {
    name: "OptionalCourse",
    data () {
      return {
        columns: [
          {
            type: 'selection',
            width: 60,
            align: 'center'
          },
          {
            title: '课程号',
            key: 'cid'
          },
          {
            title: '课程名',
            key: 'cname'
          },
          {
            title: '开课学院',
            key: 'college'
          },
          {
            title: '授课教师',
            key: 'tname'
          }
        ],
        courses: [],
        selected: [],
        status: "",
        msg: "",
        error: "",
      }
    },
    created(){
      this.getCourses();
    },
    methods: {
      getCourses(){
        this.$http.get("student", {params:{method:"getOptionalCourse",id:"B15010102"}}).then(response => {
          var result = response.body;
          if(result.status == "success"){
            this.courses = result.data;
          }else{
            alert(result.error);
          }
        }, response => {
          alert("发生错误");
        });
      },
      selectionClick(arr){
        this.selected = arr;
      },
      selectCourse(){
        if(this.selected.length == 0){
          alert("你没有选择任何课程!");
        } else{
          var selectedId = this.selected.map(x => x.cid);
          var params = "?method=selectCourse&sid=B15010102";
          for(var i=0;i<selectedId.length;i++){
            params = params + "&" + "cid=" + selectedId[i];
          }
          this.$http.get("student"+params).then(response => {
            var result = response.body;
            if(result.status == "success"){
              this.$Message.info(result.msg);
            }else{
              this.$Message.error(result.error);
            }
            this.getCourses();
          }, response => {
            this.$Message.error("发生错误");
          });
        }
      }
    }
  }

</script>


<style scoped>
  Table{
    margin-bottom:15px;
  }

  Button{
    margin-top:15px;
    font-size: 15px;
  }

</style>
