<template>
  <div id="app">
    <Student></Student>
    <!--<FooterBar class="footer"></FooterBar>-->
  </div>
</template>

<script>
  import FooterBar from '@/components/Footer'
  import Student from '@/components/Student';
export default {
  name: 'App',
  components:{Student, FooterBar}
}
</script>

<style>
#app {
  text-align: center;
  margin-left: 150px;
  margin-right: 150px;
}
</style>
