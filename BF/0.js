/*干杯29-1*/
var cBD = $G._("cBD");var cB = $G._("cB");var cR = $G._("cR");
var cv = $.createCanvas({lifeTime:29});
          var sky = $.createShape({lifeTime:29});
            var mat = $.createGradientBox(541, 384,-90, 0, 0);
            
            sky.graphics.beginGradientFill("linear" , [0xDAD0BD, 0xCBC1B0,0xDAD0BD] , [1, 1,1], [0, 128,255], mat );
            sky.graphics.drawRect(0, 0,541, 384);
            
           var obj = $.createCanvas({lifeTime:29});
            obj.blendMode = "overlay";          
           var bmp = cBD(541, 384);
           var canvas = cB({bitmapData:bmp});
            obj.addChild(canvas);
			bmp.perlinNoise(100, 100, 1 , 50 , false, true, 7, true, [$.createPoint(2, 0),$.createPoint()]);
	
			
		 var aa = $.createShape({lifeTime:29});
            var mat = $.createGradientBox(590,480,-90, -30, -60);
            
            aa.graphics.beginGradientFill("radial" , [0xDAD0BD, 0] , [0, 0.5], [ 128,235], mat );
            aa.graphics.drawRect(0, 0,591, 480);
			aa.filters = [$.createBlurFilter(10,10)];

			
			var sac = $.createCanvas({lifeTime:29,motion:{x:{fromValue:0,toValue:-541*4}}});
			for(var j = 0;j < 5;j++){
			var saa = [];
saa[j] = $.createShape({x:540*j,lifeTime:29});
            saa[j].graphics.beginFill(0x3D3A35,0.8);
            saa[j].graphics.drawRect(0, 0,541, 38);
			saa[j].graphics.drawRect(0,345,541,38);
			for(i = 10;i < 550;i = i+60){
			saa[j].graphics.drawCircle(i,10,12);
			saa[j].graphics.drawCircle(i,373,12);
			}
			sac.addChild(saa[j]);
			}
