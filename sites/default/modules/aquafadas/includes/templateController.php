<?php
  
class AquafadasTemplateController {
  protected $template_dir;
  protected $vars = array();
  public function __construct($template_dir = null){
    if($template_dir !== null){
      $this->template_dir = $template_dir;
    }
  }
  public function render($template_file){
    if(file_exists($this->template_dir.$template_file)) {
      //$template = get_include_contents($this->template_dir.$template_file);
      //return $template;
      ob_start();
      include $this->template_dir.$template_file;
      return ob_get_clean();
    } else {
      throw new Exception('no template file ' . $template_file . ' present in directory ' . $this->template_dir);
    }
  }
  public function __set($name, $value) {
    $this->vars[$name] = $value;
  }
  public function __get($name) {
    return $this->vars[$name];
  }
}  
?>