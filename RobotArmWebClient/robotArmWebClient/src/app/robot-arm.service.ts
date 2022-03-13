import { Injectable } from '@angular/core';
import { Axis } from './axes/axis';
import { AXES } from './axes/mock-axes';
import { Observable, of } from 'rxjs';
import { MessageService } from './message.service';

@Injectable({
  providedIn: 'root'
})
export class RobotArmService {

  constructor(private messageService: MessageService) { }

  getAxes():Observable< Axis[]>{
    const axes = of(AXES);
    this.messageService.add('HeroService: fetched axes');
    return axes;
  }
}
