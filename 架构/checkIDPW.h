#pragma once
/*
（登录）
判断账号密码数据库存在性
参数 user
返回值  账号不存在0 账号存在密码错误1 密码正确2
*/
int checkIDPW(User& user);