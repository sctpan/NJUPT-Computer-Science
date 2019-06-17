<template>
  <Table border :columns="columns" :data="courses"></Table>
</template>

<script>
    export default {
        name: "StudentScore",
        data () {
          return {
            columns: [
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
                key: 'cname'
              },
              {
                title: '总评成绩',
                key: 'finalScore'
              }
            ],
            courses: [],
            status: "",
            msg: "",
            error: ""
          }
        },
        created(){
            this.getCourses();
        },
        methods: {
          getCourses() {
            this.$http.get("student", {params: {method: "getScoredCourse", id: "B15010102"}}).then(response => {
              var result = response.body;
              if (result.status == "success") {
                this.courses = result.data;
              } else {
                this.$Message.error(result.error);
              }
            }, response => {
              this.$Message.error("发生错误");
            });
          },
        }
    }
</script>

<style scoped>

</style>
