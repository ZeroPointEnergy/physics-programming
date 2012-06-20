
void fun_draw ()
{
  TF1 *f1 = new TF1("f1", "exp(-x)-x",-3,3);
  f1->Draw();
}
