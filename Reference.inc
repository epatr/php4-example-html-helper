<?php
	class Reference
	{
		var $document;
		var $title;
		var $imdwidth;
		var $imgheight;

		function Reference($target, $name, $width=0, $height=0)
		{
			$this->document = $target;
			$this->title = $name;
			$this->imgwidth = $width;
			$this->imgheight = $height;
		}

		function isImage()
		{
			return(ereg("(\.jpeg$)|(\.gif$)|(\.jpg$)|(\.png$)",
				$this->document,$trash));
		}

		function insert($additionalAttributes="")
		{
			if ($this->isImage())
			{
				echo "<IMG SRC\"".$this->document."\" ALT=\"".$this->title."\"";
				if ($this->imgwidth) echo " WIDTH=".$this->imgwidth;
				if ($this->imgheight) echo " HEIGHT=".$this->imgheight;
				if ($additionalAttributes) echo " $additionalAttributes";
				echo ">";
			} else {
				echo "<A HREF=\"".$this->document."\"";
				if ($additionalAttributes) echo " $additionalAttributes";
				echo ">".$this->title."</A>";
			}
		}
	}