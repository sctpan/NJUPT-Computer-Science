<template>
  <Row id="password">
    <Col span="12" offset="6">
      <Form ref="formCustom" :model="formCustom" :rules="ruleCustom" :label-width="80">
        <FormItem label="输入密码" prop="passwd" id="form-label">
          <Input type="password" v-model="formCustom.passwd"></Input>
        </FormItem>
        <FormItem label="确认密码" prop="passwdCheck">
          <Input type="password" v-model="formCustom.passwdCheck"></Input>
        </FormItem>
        <FormItem>
          <Button type="primary" @click="handleSubmit('formCustom')">修改密码</Button>
          <Button @click="handleReset('formCustom')" style="margin-left: 8px">清空</Button>
        </FormItem>
      </Form>
    </Col>
  </Row>

</template>
<script>
  export default {
    data () {
      const validatePass = (rule, value, callback) => {
        if (value === '') {
          callback(new Error('请输入密码'));
        } else {
          if (this.formCustom.passwdCheck !== '') {
            this.$refs.formCustom.validateField('passwdCheck');
          }
          callback();
        }
      };
      const validatePassCheck = (rule, value, callback) => {
        if (value === '') {
          callback(new Error('请再次输入密码'));
        } else if (value !== this.formCustom.passwd) {
          callback(new Error('两次输入不相等!'));
        } else {
          callback();
        }
      };


      return {
        formCustom: {
          passwd: '',
          passwdCheck: '',
        },
        ruleCustom: {
          passwd: [
            { validator: validatePass, trigger: 'blur' }
          ],
          passwdCheck: [
            { validator: validatePassCheck, trigger: 'blur' }
          ],
        }
      }
    },
    methods: {
      handleSubmit (name) {
        this.$refs[name].validate((valid) => {
          if (valid) {
            this.$http.get("student", {params:{method:"updatePassword",id:"B15010102",password:this.formCustom.passwd}}).then(response => {
              var result = response.body;
              if(result.status == "success"){
                this.$Message.success('修改密码成功!');
              }else{
                this.$Message.error('修改密码失败!');
              }
            }, response => {
              this.$Message.error("发生错误");
            });
          } else {
            this.$Message.error('修改密码失败!');
          }
        })
      },
      handleReset (name) {
        this.$refs[name].resetFields();
      }
    }
  }
</script>
<style>
  #password{
    margin-top: 60px;
  }
  .ivu-form-item-label{
    font-size: 14px !important;
  }
</style>
