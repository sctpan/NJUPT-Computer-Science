<template>
  <div id="student">
    <StudentNav class="nav"></StudentNav>
    <router-view></router-view>
  </div>
</template>

<script>
    import StudentNav from '@/components/StudentNav'
    import OptionalCourse from '@/components/OptionalCourse'
    import SelectedCourse from '@/components/SelectedCourse'
    import StudentScore from '@/components/StudentScore'
    import Password from '@/components/Password'
    export default {
        name: "Student",
        components: {StudentNav,OptionalCourse,SelectedCourse,StudentScore,Password}
    }
</script>

<style scoped>
  .nav{
    margin-bottom: 20px;
  }

</style>
