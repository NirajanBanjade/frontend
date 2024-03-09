import { useState } from "react";
import "./App.css";
import {Parser} from 'expr-eval';


function App() {
  const [screen,setScreen]=useState('0');
  const [expression,setExpression]=useState('');

  const addToScreen=(value)=>{

      if (value==='C'){
        setScreen('0');
        setExpression('');
      }
      else if(value==='A'){
        if (!expression) {
          // Handle case where no expression is available
          setScreen('Error: No expression to evaluate');
          return;
      }
        console.log(expression);
        const parser=new Parser();


        try{
        const exp=parser.parse(expression.trim());
        const result=exp.evaluate();
        setScreen(String(result));
        setExpression("");
        }
        catch(error){
          console.error('Error evaluating expression:', error);
          setScreen('Error');
          setExpression('');
        }
      }
      else{
      
      setScreen(function(prev){
        if(prev==='0'){
          return value;
        }
        else{
          return prev+value;
        }

      });
      setExpression(function(s){
        return s+value;
      });
    }
  }
  return (
    <>
    <div className="table">
      <table>
        <div className="calcScreen">

        {screen}
        </div>
        <div className="buttons">
          <div className="first">
            <button onClick={()=>addToScreen('1')}>1</button>
            <button  onClick={()=>addToScreen('2')}>2</button>
            <button  onClick={()=>addToScreen('3')}>3</button>
            <button  onClick={()=>addToScreen('*')}>*</button>
          </div>
          <div className="second">
            <button  onClick={()=>addToScreen('4')}>4</button>
            <button  onClick={()=>addToScreen('5')}>5</button>
            <button  onClick={()=>addToScreen('6')}>6</button>
            <button  onClick={()=>addToScreen('+')}>+</button>
          </div>

          <div className="third" >
            <button  onClick={()=>addToScreen('7')}>7</button>
            <button  onClick={()=>addToScreen('8')}>8</button>
            <button onClick={()=>addToScreen('9')}>9</button>
            <button onClick={()=>addToScreen('-')}>-</button>
          </div>
          <div className="fourth" >
            <button onClick={()=>addToScreen('0')}>0</button>
            <button onClick={()=>addToScreen('/')}>/</button>
            <button onClick={()=>addToScreen('C')}>Clr</button>
            <button onClick={()=>addToScreen('A')}>ANS</button>
          </div>
        </div>
      </table>
    </div>
  
    </>
  );
}

export default App;
