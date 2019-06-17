// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
import vueResource from 'vue-resource'
import iView from 'iview';
import 'iview/dist/styles/iview.css';
Vue.use(vueResource);
Vue.use(iView);

Vue.config.productionTip = false
Vue.http.options.root = "http://localhost:8080/api/";
Vue.http.options.emulateJSON = "true";
/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  components: { App },
  template: '<App/>'
})
