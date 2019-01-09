缩短比特币现金出块时间至2分钟的BCH节点
---------------------

众所周知，自2009年1月创世块出现以来，比特币系统已经运行了整整10年时间，作为比
特币社区著名的“扩容之争”结果，比特币现金于2017年8月1日从比特币（Bitcoin Core）
网络分叉出来，大幅提高了区块容量、去除了隔离见证代码，大幅降低了转账手续费，
成功获得了大量大区块支持者，拥有多个开发团队，是比特币系的主要分支之一。

比特币系统运行至今，平均出块时间一直保持在10分钟，而网络技术已经在这10年中已经
取得飞跃式的发展，网络延迟大幅降低、网络带宽提升10倍以上。本节点程序尝试将出块
时间降低至2分钟，同时将区块奖励降低为1/5，这可以使得比特币现金的发行速度跟原来
保持一致，未来产量再次减半的时间点也与原来保持一致。

关于出块时间，已有不少BCH持有者进行了[签名投票](http://votes.cash/)，结果显示造成缩短区块时间
的用户占比高达98.88%，缩短区块时间可以大幅提升用户体验，可以带来更多的用户。

本程序包括2种共识修改：

1、出块时间从10分钟修改为2分钟，默认2019年5月激活，可通过在bitcoin.conf中加入
“greatwallactivationtime=时间戳” 语句的方式提前激活，用于测试；

2、区块奖励自分叉时起降低为1/5，节点程序为保持BCH发行总量不变，采用了按照高度
激活的方式，可通过在bitcoin.conf中加入“shortspacingactivationheight=激活高度”
语句的方式提前激活，默认值为582910，大约是5月份基于时间戳的硬分叉激活后的第240
个区块，采用区块高度激活可以确保发行总量、发行速度不变，且不会产生不确定状态。

如何运行
---------------------
运行以下语句配置编译环境

$ ./autogen.sh

$ ./configure --prefix=/your_install_path --disable-gui --disable-tests

然后运行以下语句编译&安装

$ make && make install

最后进入安装目录运行BCH客户端

$ ./bitcoind -daemon

或

$ ./bitcoind -testnet -daemon

注意如果需要提前激活分叉，需要提前配置好bitcoin.conf文件

[Bitcoin ABC](https://www.bitcoinabc.org)
===========

The goal of Bitcoin ABC is to create sound money that is usable by everyone in
the world. We believe this is a civilization-changing technology which will
dramatically increase human flourishing, freedom, and prosperity. The project
aims to achieve this goal by implementing a series of optimizations and
protocol upgrades that will enable peer-to-peer digital cash to scale many
orders of magnitude beyond current limits.

What is Bitcoin Cash?
---------------------

[Bitcoin Cash](https://www.bitcoincash.org/) is an experimental digital
currency that enables instant payments to anyone, anywhere in the world. It
uses peer-to-peer technology to operate with no central authority: managing
transactions and issuing money are carried out collectively by the network.
Bitcoin Cash is a descendant of Bitcoin. It became a separate currency from
the version supported by Bitcoin Core when the two split on August 1, 2017.
Bitcoin Cash and the Bitcoin Core version of Bitcoin share the same
transaction history up until the split.

What is Bitcoin ABC?
--------------------

Bitcoin ABC is the name of open-source software which enables the use of
Bitcoin Cash. It is a fork of the [Bitcoin Core](https://bitcoincore.org)
software project.

License
-------

Bitcoin ABC is released under the terms of the MIT license. See
[COPYING](COPYING) for more information or see
https://opensource.org/licenses/MIT.

Development Process
-------------------

This Github repository contains only source code of releases.

Bitcoin ABC development takes place at https://reviews.bitcoinabc.org/

If you would like to contribute, please read [CONTRIBUTING](CONTRIBUTING.md).

Disclosure Policy
-----------------

See [DISCLOSURE_POLICY](DISCLOSURE_POLICY.md)
