import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import OptionalCourse from '@/components/OptionalCourse'
import SelectedCourse from '@/components/SelectedCourse'
import StudentScore from '@/components/StudentScore'
import Password from '@/components/Password'
Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'HelloWorld',
      component: HelloWorld
    },
    {
      path: '/student/optionalCourse',
      name: 'optionalCourse',
      component: OptionalCourse
    },
    {
      path: '/student/selectedCourse',
      name: 'selectedCourse',
      component: SelectedCourse
    },
    {
      path: '/student/studentScore',
      name: 'studentScore',
      component: StudentScore
    },
    {
      path: '/student/password',
      name: 'password',
      component: Password
    }
  ]
})
